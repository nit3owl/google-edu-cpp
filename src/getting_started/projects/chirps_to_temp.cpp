#include <iostream>

double CalculateTemp(int chirps) {
    return (chirps + 40) / 4;
}

int main() {
    int chirps;

    std::cout << "Number of chirps: ";
    if(!(std::cin >> chirps) || chirps < 0) {
        std::cout << "Expected positive integer input; exiting." << std::endl;
        return 1;
    }

    std::cout << "The temperature is: " << CalculateTemp(chirps) << " degrees." << std::endl;

    return 0;
}
