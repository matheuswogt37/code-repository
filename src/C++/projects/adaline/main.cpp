#include <iostream>
#include <vector>
#include <numeric> // For std::inner_product
#include <cmath>   // For std::rand, std::srand

double MAX_ERROR_RATE = 0.01;


class Adaline {
public:
    Adaline(int numInputs, double learningRate_ = 0.1) : learningRate(learningRate_) {
        weights.resize(numInputs);
        // Initialize weights with small random values
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

    void train(const std::vector<std::vector<double>>& inputs, const std::vector<double>& targets) {
        double epoch = 1;
        double totalError;
        do
        {
            totalError = 0.0;
            for (size_t i = 0; i < inputs.size(); i++) {
                double netInput = calculateNetInput(inputs[i]);
                double error = targets[i] - netInput;
                totalError += error;
                for (size_t j = 0; j < weights.size(); j++) {
                    weights[j] += learningRate * error * inputs[i][j];
                }
                bias += learningRate * error;
            }
            totalError *= 0.5;
            std::cout << "Epoch " << epoch << ", Total Squared Error: " << totalError << std::endl;
            epoch++;
        } while (totalError > MAX_ERROR_RATE || epoch <= 10);
    }

    int predict(const std::vector<double>& input) const {
        double netInput = calculateNetInput(input);
        return (netInput >= 0.5) ? 1 : 0; // Bipolar activation function for classification
    }

    void run(const std::vector<double> input) {
        int output = predict(input);
        for (int i = 0; i < input.size(); i++) {
            std::cout << input[i] << " ";
        }
        std::cout << " -> " << output << "\n";
    }

    void runBatch(const std::vector<std::vector<double>> inputs) {
        for (int i = 0; i < inputs.size(); i++) {
            run(inputs[i]);
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

// Main function to demonstrate usage (not included for brevity)
int main() { 
    Adaline ada(2);
    std::vector<std::vector<double>> inputs = {
        {0, 0},
        {1, 0},
        {0, 1},
        {1, 1}
    };
    
    //! OR
    std::cout << "\nOR training!\n";
    std::vector<double> result_train_OR = {0, 1, 1, 1};
    ada.train(inputs, result_train_OR);
    ada.runBatch(inputs); //* run using the train inputs but this is only for test all occurrences

    //! AND
    ada.resetWeight();
    std::cout << "\nAND training!\n";
    std::vector<double> result_train_AND = {0, 0, 0, 1};
    ada.train(inputs, result_train_AND);
    ada.runBatch(inputs); //* run using the train inputs but this is only for test all occurrences
    
    //! XOR
    ada.resetWeight();
    std::cout << "\nXOR training!\n";
    std::vector<double> result_train_XOR = {0, 1, 1, 0};
    ada.train(inputs, result_train_XOR);
    ada.runBatch(inputs); //* run using the train inputs but this is only for test all occurrences

    return 0;
}