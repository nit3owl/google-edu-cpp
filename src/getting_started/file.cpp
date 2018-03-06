#include <fstream>
#include <iostream>

int main() {
    char firstName[30], lastName[30], fileName[30];
    int age;
    char dataEntry = 'y';

    std::cout << std::endl << "Enter output file name: ";
    std::cin >> fileName;
    std::ofstream People(fileName, std::ios::out);

    do {
        std::cout << "Enter first name: ";
        std::cin >> firstName;

        std::cout << "Enter last name: ";
        std::cin >> lastName;

        std::cout << "Enter age: ";
        std::cin >> age;

        People << lastName << ", " << firstName << " age: " << age << std::endl;     

        std::cout << "Continue? (y/n): ";
        std::cin >> dataEntry;                                       
    } while ('n' != dataEntry);

    People.close();

    std::cout << "Saved the following data:" << std::endl;
    std::ifstream People_in(fileName);
    std::string line;

    while(std::getline(People_in, line)){
        std::cout << line << std::endl;
    }
    People_in.close();

    return 0;
}
