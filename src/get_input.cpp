#include <iostream>
#include <limits>

int main() {
    int input_var = 0;

    do {
        std::cout << "Enter a number (-1 to exit): ";
        if (!(std::cin >> input_var)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Non-numeric input; please enter a number." << std::endl;
        } else { 
            if (input_var != 1) {
                std::cout << "You entered " << input_var << std::endl;
            }
        }
    } while (input_var != -1);

    std::cout << "Exiting." << std::endl;
    return 0;
}
