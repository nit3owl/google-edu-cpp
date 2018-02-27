#include <iostream>
#include <cstdlib>
#include <limits>

int main() {
    srand (time(NULL));

    int target = (rand() % 100) + 1;
    int input;

    std::cout << "Guess a number between 1 and 100" << std::endl;

    do {
        std::cout << "Enter a guess: ";
        if(!(std::cin >> input)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            if (input < target) {
                std::cout << "Try guessing higher..." << std::endl;
            } else {
                std::cout << "Try guessing lower..." << std::endl;
            }
        }
    } while (input != target);

    std::cout << "You got it! The number was " << target << ". Game over." << std::endl;

    return 0;
}
