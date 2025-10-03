#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <random>
#include <numeric>
#include <algorithm>
#include <ctime>

//! parameters 
const int QTD_INDIVIDUALS = 500;
const int QTD_GENERATIONS = 5000;
const int QTD_ELITISM = 1;
const int QTD_CROSSOVER = 40;
const int QTD_TOURNMENT = 10;
const double MUTATION_RATE = 0.1;
const double PENALTY_WEIGHT_PROFIT = 5000.0;
const double PENALTY_VOL_PROFIT = 5000.0;

//! cargo informations
const double CARGO_PROFIT[] = {310.0, 380.0, 350.0, 285.0};
const double CARGO_WEIGHT[] = {18.0, 15.0, 23.0, 12.0};
const double CARGO_VOL[] = {480.0, 650.0, 580.0, 390.0};
//! plane informations
const double PLANE_WEIGHT[] = {10.0, 16.0, 8.0};
const double PLANE_VOL[] = {6800.0, 8700.0, 5300.0};

// global RNG
static std::mt19937 rng((unsigned)time(nullptr));

// helper: index cargo/compartimento
inline int idx(int cargo, int comp) { return cargo + comp*4; }

// uniform double helper
double uniform_double(double a, double b) {
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
}

// Dirichlet sampler (alpha vector, precision optional)
std::vector<double> sampleDirichlet(const std::vector<double>& alpha_params, int precision = 6) {
    size_t K = alpha_params.size();
    std::vector<double> gammas(K);
    for (size_t i = 0; i < K; ++i) {
        std::gamma_distribution<double> gdist(alpha_params[i], 1.0);
        gammas[i] = gdist(rng);
    }
    double sum = std::accumulate(gammas.begin(), gammas.end(), 0.0);
    std::vector<double> res(K, 0.0);
    if (sum > 0.0) {
        for (size_t i=0;i<K;i++) res[i] = gammas[i] / sum;
        // normalize to avoid rounding issues
        double s = std::accumulate(res.begin(), res.end(), 0.0);
        if (s > 0.0) for (size_t i=0;i<K;i++) res[i] /= s;
    } else {
        // fallback uniform
        for (size_t i=0;i<K;i++) res[i] = 1.0 / double(K);
    }
    return res;
}

// repair: garante constraints por carga e por compartimento (peso e volume)
void repairIndividual(std::vector<double> &ind) {
    const double EPS = 1e-12;
    // não-negativos
    for (double &v : ind) if (v < 0.0) v = 0.0;

    // iterar para conciliar restrições cargo <-> compartimento
    for (int iter = 0; iter < 8; ++iter) {
        // 1) limitar cada carga à sua disponibilidade
        for (int cargo = 0; cargo < 4; ++cargo) {
            double s = ind[idx(cargo,0)] + ind[idx(cargo,1)] + ind[idx(cargo,2)];
            if (s > CARGO_WEIGHT[cargo] + EPS) {
                double f = CARGO_WEIGHT[cargo] / s;
                for (int comp = 0; comp < 3; ++comp) ind[idx(cargo,comp)] *= f;
            }
        }

        // 2) limitar por compartimento (peso e volume)
        bool anyChange = false;
        for (int comp = 0; comp < 3; ++comp) {
            double weightSum = 0.0;
            double volSum = 0.0;
            for (int cargo = 0; cargo < 4; ++cargo) {
                double v = ind[idx(cargo, comp)];
                weightSum += v;
                volSum += v * CARGO_VOL[cargo];
            }
            double fW = 1.0, fV = 1.0;
            if (weightSum > PLANE_WEIGHT[comp] + EPS) fW = PLANE_WEIGHT[comp] / weightSum;
            if (volSum   > PLANE_VOL[comp]   + EPS) fV = PLANE_VOL[comp]   / volSum;
            double f = std::min({1.0, fW, fV});
            if (f < 1.0 - 1e-12) {
                for (int cargo = 0; cargo < 4; ++cargo) ind[idx(cargo, comp)] *= f;
                anyChange = true;
            }
        }
        if (!anyChange) break;
    }

    // limpar valores muito pequenos
    for (double &v : ind) if (v < 1e-9) v = 0.0;
}

// create individual: aloca toneladas por carga e divide entre 3 compartimentos
std::pair<std::vector<double>, double> createIndividual() {
    std::vector<double> ind(12, 0.0);
    for (int cargo = 0; cargo < 4; ++cargo) {
        double allocated = uniform_double(0.0, CARGO_WEIGHT[cargo]); // toneladas dessa carga
        std::vector<double> prop = sampleDirichlet({1.0,1.0,1.0}, 6);
        ind[idx(cargo,0)] = allocated * prop[0];
        ind[idx(cargo,1)] = allocated * prop[1];
        ind[idx(cargo,2)] = allocated * prop[2];
    }
    repairIndividual(ind);
    return {ind, 0.0};
}

// fitness simplificado (lucro se válido; senão penaliza)
void fitness(std::vector<std::pair<std::vector<double>, double>> &generation) {
    for (auto &p : generation) {
        bool valid = true;
        double profit = 0.0;

        // lucro por carga e disponibilidade
        for (int cargo = 0; cargo < 4; ++cargo) {
            double s = p.first[idx(cargo,0)] + p.first[idx(cargo,1)] + p.first[idx(cargo,2)];
            if (s > CARGO_WEIGHT[cargo] + 1e-9) valid = false;
            profit += s * CARGO_PROFIT[cargo];
        }

        // verifica limites por compartimento
        for (int comp = 0; comp < 3; ++comp) {
            double w = 0.0, v = 0.0;
            for (int cargo = 0; cargo < 4; ++cargo) {
                w += p.first[idx(cargo, comp)];
                v += p.first[idx(cargo, comp)] * CARGO_VOL[cargo];
            }
            if (w > PLANE_WEIGHT[comp] + 1e-9 || v > PLANE_VOL[comp] + 1e-9) valid = false;
        }

        if (valid) p.second = profit;
        else p.second = profit * 0.1; // penaliza fortemente
    }
}

// tournament selection (por referência) -> retorna genoma do vencedor
std::vector<double> tournment(const std::vector<std::pair<std::vector<double>, double>> &pop) {
    std::uniform_int_distribution<int> dist(0, (int)pop.size()-1);
    int best = dist(rng);
    double bestF = pop[best].second;
    for (int t = 1; t < QTD_TOURNMENT; ++t) {
        int cand = dist(rng);
        if (pop[cand].second > bestF) {
            best = cand;
            bestF = pop[cand].second;
        }
    }
    return pop[best].first;
}

// crossover 1-point + mutação discreta (±1 ton por gene), repara no final
std::pair<std::vector<double>, double> crossover(const std::vector<double> &ch1, const std::vector<double> &ch2) {
    std::vector<double> child;
    const std::vector<double> *father = &ch1;
    const std::vector<double> *mother = &ch2;
    if (uniform_double(0.0,1.0) < 0.5) { father = &ch2; mother = &ch1; }

    int cut = std::uniform_int_distribution<int>(0,11)(rng);
    for (int i=0;i<cut;i++) child.push_back((*father)[i]);
    for (int i=cut;i<12;i++) child.push_back((*mother)[i]);

    // mutação por gene
    std::uniform_real_distribution<double> u01(0.0,1.0);
    std::uniform_int_distribution<int> coin(0,1);
    for (int i=0;i<12;i++) {
        if (u01(rng) < MUTATION_RATE) {
            int s = (coin(rng) == 0) ? -1 : 1;
            child[i] += double(s) * 1.0;
            if (child[i] < 0.0) child[i] = 0.0;
        }
    }

    repairIndividual(child);
    return {child, 0.0};
}

std::vector<double> run() {
    std::vector<std::pair<std::vector<double>, double>> generation;
    generation.reserve(QTD_INDIVIDUALS);

    // população inicial
    for (int i=0;i<QTD_INDIVIDUALS;i++) generation.push_back(createIndividual());

    for (int gen=0; gen<QTD_GENERATIONS; ++gen) {
        // avalia população atual
        for (auto &p : generation) repairIndividual(p.first); // segurança extra
        fitness(generation);

        // ordena descending (melhor primeiro)
        std::sort(generation.begin(), generation.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });

        if (gen % 50 == 0) {
            double avg = 0.0;
            for (auto &p : generation) avg += p.second;
            avg /= generation.size();
            std::cout << "Gen " << gen << " best = " << generation.front().second << " avg = " << avg << "\n";
        }

        // nova geração
        std::vector<std::pair<std::vector<double>, double>> newGen;
        newGen.reserve(QTD_INDIVIDUALS);

        // elitismo
        for (int e=0;e<QTD_ELITISM && e < (int)generation.size(); ++e) newGen.push_back(generation[e]);

        // filhos via torneio + crossover
        while ((int)newGen.size() < QTD_ELITISM + QTD_CROSSOVER) {
            std::vector<double> father = tournment(generation);
            std::vector<double> mother = tournment(generation);
            newGen.push_back(crossover(father, mother));
        }

        // completar com aleatórios
        while ((int)newGen.size() < QTD_INDIVIDUALS) newGen.push_back(createIndividual());

        // garantia adicional: reparar qualquer indivíduo
        for (auto &p : newGen) repairIndividual(p.first);

        generation.swap(newGen);
    }

    // avaliação final
    for (auto &p : generation) repairIndividual(p.first);
    fitness(generation);
    std::sort(generation.begin(), generation.end(), [](const auto &a, const auto &b){ return a.second > b.second; });

    return generation.front().first;
}

int main() {
    auto best = run();

    // calcular peso e lucro por compartimento
    double planeWeights[3] = {0.0,0.0,0.0};
    double planeProfits[3] = {0.0,0.0,0.0};
    for (int comp = 0; comp < 3; ++comp) {
        for (int cargo = 0; cargo < 4; ++cargo) {
            planeWeights[comp] += best[idx(cargo, comp)];
            planeProfits[comp] += best[idx(cargo, comp)] * CARGO_PROFIT[cargo];
        }
    }

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "-----------------------------------\nThe best organization:\n";
    std::cout << "D " << planeWeights[0] << " = R$" << planeProfits[0] << "\n";
    std::cout << "C " << planeWeights[1] << " = R$" << planeProfits[1] << "\n";
    std::cout << "T " << planeWeights[2] << " = R$" << planeProfits[2] << "\n";
    std::cout << "Profit = R$" << (planeProfits[0]+planeProfits[1]+planeProfits[2]) << "\n\n";

    std::cout << "Per-cargo totals:\n";
    for (int cargo = 0; cargo < 4; ++cargo) {
        double s = best[idx(cargo,0)] + best[idx(cargo,1)] + best[idx(cargo,2)];
        std::cout << "C" << cargo+1 << " total = " << s << " (avail " << CARGO_WEIGHT[cargo] << ") -> R$" << s * CARGO_PROFIT[cargo] << "\n";
    }

    std::cout << "\nDetailed allocation (C1D, C2D, C3D, C4D, C1C, ...):\n";
    for (int i=0;i<12;i++) {
        int cargo = i % 4;
        std::cout << "[" << i << "] = " << best[i] << " -> R$" << best[i] * CARGO_PROFIT[cargo] << "\n";
    }

    return 0;
}
