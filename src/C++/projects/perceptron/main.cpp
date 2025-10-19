#include <iostream>
#include <vector>
#include <numeric> // For std::inner_product
#include <cstdlib> // For rand, srand
#include <ctime>   // For time

int EPOCHS = 10;

class Perceptron {
public:
    Perceptron(int numInputs, double learningRate_ = 0.1) : learningRate(learningRate_) {
        srand(time(nullptr));
        weights.resize(numInputs);
        setWeights(numInputs);
    }

    void setWeights(int numInputs) {
        for (int i = 0; i < numInputs; ++i) {
            weights[i] = (static_cast<double>(rand()) / RAND_MAX) * 0.1 - 0.05; // -0.05 to 0.05
        }
        bias = (static_cast<double>(rand()) / RAND_MAX) * 0.1 - 0.05;
    }

    void resetWeight() {
        setWeights(this->weights.size());
    }

    void train(const std::vector<std::vector<double>>& inputs, const std::vector<double>& targets, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            double totalError = 0.0;

            for (size_t i = 0; i < inputs.size(); ++i) {
                int output = predict(inputs[i]);
                double error = targets[i] - output;

                for (size_t j = 0; j < weights.size(); ++j) {
                    weights[j] += learningRate * error * inputs[i][j];
                }
                bias += learningRate * error;

                totalError += std::abs(error);
            }

            std::cout << "Epoch " << epoch + 1 << " - Total error: " << totalError << "\n";
        }

        // Mostrar pesos finais
        std::cout << "Final weights: ";
        for (double w : weights) std::cout << w << " ";
        std::cout << "Bias: " << bias << "\n";
    }

    int predict(const std::vector<double>& input) const {
        double netInput = calculateNetInput(input);
        return (netInput >= 0.0) ? 1 : 0; // Step function (limiar em 0)
    }

    void run(const std::vector<double>& input) {
        int output = predict(input);
        for (double v : input) std::cout << v << " ";
        std::cout << " -> " << output << "\n";
    }

    void runBatch(const std::vector<std::vector<double>>& inputs) {
        for (const auto& input : inputs) {
            run(input);
        }
    }

private:
    double calculateNetInput(const std::vector<double>& input) const {
        return std::inner_product(input.begin(), input.end(), weights.begin(), 0.0) + bias;
    }

    std::vector<double> weights;
    double bias;
    double learningRate;
};

int main() {
    Perceptron p(2);
    std::vector<std::vector<double>> inputs = {
        {0, 0},
        {1, 0},
        {0, 1},
        {1, 1}
    };

    //! OR
    std::cout << "\n=== OR training ===\n";
    std::vector<double> result_train_OR = {0, 1, 1, 1};
    p.train(inputs, result_train_OR, EPOCHS);
    p.runBatch(inputs);

    //! AND
    p.resetWeight();
    std::cout << "\n=== AND training ===\n";
    std::vector<double> result_train_AND = {0, 0, 0, 1};
    p.train(inputs, result_train_AND, EPOCHS);
    p.runBatch(inputs);

    //! XOR
    p.resetWeight();
    std::cout << "\n=== XOR training ===\n";
    std::vector<double> result_train_XOR = {0, 1, 1, 0};
    p.train(inputs, result_train_XOR, EPOCHS);
    p.runBatch(inputs);

    return 0;
}
