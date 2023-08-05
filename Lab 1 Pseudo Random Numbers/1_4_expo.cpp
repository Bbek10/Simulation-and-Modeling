#include <iostream>
#include <random>
#include <cmath>

int main() {
    std::default_random_engine generator;
    std::exponential_distribution<double> distribution(0.5);

    generator.seed(2341); // Set the seed

    double mean = 0;
    double variance = 0;
    int nSample = 10000;

    for (int i = 0; i < nSample; i++) {
        double r = distribution(generator);
        mean += r;
        variance += r * r;
    }

    mean /= nSample;
    variance = variance / nSample - mean * mean; // Variance formula

    std::cout << "Sample Mean: " << mean << std::endl;
    std::cout << "Sample Variance: " << variance << std::endl;

    // Expected mean and variance for exponential distribution with rate λ = 0.5
    double expected_mean = 1 / 0.5;
    double expected_variance = 1 / (0.5 * 0.5);

    std::cout << "Expected Mean: " << expected_mean << std::endl;
    std::cout << "Expected Variance: " << expected_variance << std::endl;

    // Calculate the differences between sample and expected mean/variance
    double mean_difference = std::abs(mean - expected_mean);
    double variance_difference = std::abs(variance - expected_variance);

    std::cout << "Mean Difference: " << mean_difference << std::endl;
    std::cout << "Variance Difference: " << variance_difference << std::endl;

    return 0;
}
