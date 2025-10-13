#include <iostream>
#include <vector>
#include <cstdlib> //* to random numbers
#include <ctime>

const double MAX_RNG_INIT_VALUE = 0.1;
const int QTD_ENTRIES = 2;
const int QTD_BIAS = 1;
const double ACTIVATION_VALUE = 0.5;
const double ERROR_TRAIN_VALUE = 0.1;
const int NUM_MAX_EPOCH = 100;

void initNeuron(std::vector<double> *bias, std::vector<std::vector<double>> *heightEntryBia) {
    std::vector<double> tempHeights;
    bias->clear();
    heightEntryBia->clear();

    //! rng bias
    for (int i = 0; i < QTD_BIAS; i++) {
        if (MAX_RNG_INIT_VALUE != 0.0) {
            bias->push_back((rand() % (int (MAX_RNG_INIT_VALUE * 10))) / 10.0);
        } else {
            bias->push_back(0.0);
        }
    }

    //! rng weight entry -> bias
    for (int i = 0; i < QTD_BIAS; i++) {
        tempHeights.clear();
        for (int j = 0; j < QTD_ENTRIES; j++) {
            if (MAX_RNG_INIT_VALUE != 0.0) {
                tempHeights.push_back((rand() % (int (MAX_RNG_INIT_VALUE * 10))) / 10.0);
            } else {
                tempHeights.push_back(0.0);
            }
        }
        heightEntryBia->push_back(tempHeights);
    }
}

int activationFunction(double val) {
    return (val >= ACTIVATION_VALUE) ? 1 : 0;
}

int run(std::vector<int> entries, std::vector<double> bias, std::vector<std::vector<double>> heightEntryBia) {
    double val = 0;
    //! entrie[0] * weight[0][0] + entrie[1] * weight[0][1]
    for (int i = 0; i < QTD_ENTRIES; i++) {
        for (int j = 0; j < QTD_BIAS; j++) {
            val += entries[i] * heightEntryBia[j][i];
        }
    }
    for (int i = 0; i < QTD_BIAS; i++) {
        val += bias[i];
    }

    return activationFunction(val);
}

void train(std::vector<double> *bias, std::vector<std::vector<double>> *heightEntryBia, 
           std::vector<std::vector<int>> entries, std::vector<int> goals) {

    int epoch = 0;
    int count = 0;
    while (count < (int)entries.size()) {
        std::vector<int> temp = entries[count];
        
        int res = run(temp, *bias, *heightEntryBia);
        if (res == goals[count]) {
            count++;
        } else { //! adjust weights
            // w_i ← w_i + η * (y_esperado – y_obtido) * x_i
            for (int i = 0; i < QTD_ENTRIES; i++) {
                for (int j = 0; j < QTD_BIAS; j++) {
                    (*heightEntryBia)[j][i] = (*heightEntryBia)[j][i] + ERROR_TRAIN_VALUE * (goals[count] - res) * temp[i];
                }
            }
            // b ← b + η * (y_esperado – y_obtido)
            for (int i = 0; i < QTD_BIAS; i++) {
                (*bias)[i] = (*bias)[i] + ERROR_TRAIN_VALUE * (goals[count] - res);
            }
            // volta pro início do dataset
            count = 0;
        }

        epoch++;
        if (epoch >= NUM_MAX_EPOCH) {
            break;
        }
    }

    std::cout << "Finish train with " << epoch << " epoch(s)\n";
    std::cout << "Final weights and bias:\n";
    for (int j = 0; j < QTD_BIAS; j++) {
        for (int i = 0; i < QTD_ENTRIES; i++) {
            std::cout << "  w[" << j << "][" << i << "] = " << (*heightEntryBia)[j][i] << "\n";
        }
    }
    for (int i = 0; i < QTD_BIAS; i++) {
        std::cout << "  bias[" << i << "] = " << (*bias)[i] << "\n";
    }
    std::cout << "--------------------------\n";
}

int main() {
    srand(time(0)); //* grant new rng's every run

    std::vector<double> bias;
    std::vector<std::vector<double>> heightEntryBias;

    // ------------------------------------
    // OR training
    // ------------------------------------
    initNeuron(&bias, &heightEntryBias);
    std::vector<std::vector<int>> or_train_entry = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    std::vector<int> or_train_goals = {0, 1, 1, 1};

    std::cout << "\n=== Training OR ===\n";
    train(&bias, &heightEntryBias, or_train_entry, or_train_goals);

    std::cout << "Testing OR:\n";
    std::cout << "0 OR 0 = " << run({0, 0}, bias, heightEntryBias) << "\n";
    std::cout << "0 OR 1 = " << run({0, 1}, bias, heightEntryBias) << "\n";
    std::cout << "1 OR 0 = " << run({1, 0}, bias, heightEntryBias) << "\n";
    std::cout << "1 OR 1 = " << run({1, 1}, bias, heightEntryBias) << "\n\n";

    // ------------------------------------
    // AND training
    // ------------------------------------
    initNeuron(&bias, &heightEntryBias);
    std::vector<std::vector<int>> and_train_entry = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    std::vector<int> and_train_goals = {0, 0, 0, 1};

    std::cout << "\n=== Training AND ===\n";
    train(&bias, &heightEntryBias, and_train_entry, and_train_goals);

    std::cout << "Testing AND:\n";
    std::cout << "0 AND 0 = " << run({0, 0}, bias, heightEntryBias) << "\n";
    std::cout << "0 AND 1 = " << run({0, 1}, bias, heightEntryBias) << "\n";
    std::cout << "1 AND 0 = " << run({1, 0}, bias, heightEntryBias) << "\n";
    std::cout << "1 AND 1 = " << run({1, 1}, bias, heightEntryBias) << "\n";

    // ======================
    // XOR training
    // ======================
    initNeuron(&bias, &heightEntryBias);
    std::vector<std::vector<int>> xor_train_entry = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    std::vector<int> xor_train_goals = {0, 1, 1, 0};

    std::cout << "\n=== Training XOR (Perceptron simples) ===\n";
    train(&bias, &heightEntryBias, xor_train_entry, xor_train_goals);

    std::cout << "Testing XOR:\n";
    std::cout << "0 XOR 0 = " << run({0, 0}, bias, heightEntryBias) << "\n";
    std::cout << "0 XOR 1 = " << run({0, 1}, bias, heightEntryBias) << "\n";
    std::cout << "1 XOR 0 = " << run({1, 0}, bias, heightEntryBias) << "\n";
    std::cout << "1 XOR 1 = " << run({1, 1}, bias, heightEntryBias) << "\n";

    return 0;
}
