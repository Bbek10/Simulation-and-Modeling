#include <iostream>
#include <random>
#include <fstream>

int main() {
    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(0.5);

    generator.seed(2341); // Set the seed

    int nSample = 10000;
    std::ofstream outFile("random_numbers.csv");

    for (int i = 0; i < nSample; i++) {
        double r = distribution(generator);
        outFile << r << "\n";
    }

    outFile.close();

    return 0;
}
