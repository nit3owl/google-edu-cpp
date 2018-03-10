#include <iostream>
#include <ctype.h>

int kBaseYear = 1995;

int DecodeMonth(char c) {
    c = toupper(c);
    if(c < 65 || c > 76)
        throw std::invalid_argument("Months must be 'A' through 'L");
    
    return c - 64;
}

int DecodeDay(char c) {
    c = toupper(c);
    if(c < 81 || c > 90)
        throw std::invalid_argument("Days must be 'Q' through 'Z");
    
    return c - 81;
}

int DecodeYear(char c) {
    c = toupper(c);
    
    return (c - 64) + kBaseYear;
}

void ValidateInput(std::string input) {
    if(input.length() != 4)
        throw std::invalid_argument("Input must be four alpha characters.");  
    
    for(int i = 0; i < 4; i++) {
        if(!(isalpha(input[i])))
            throw std::invalid_argument("Input must be four alpha characters."); 
    }
}

int main() {
    std::string input;

    std::cout << "Enter a four aplha character expiration (months: 'A'-'L', days: 'Q'-'Z', years: 'A'-'Z'): ";
    if(!(std::cin >> input)) {
        std::cout << "Error; exiting." << std::endl;
    }

    try {
        ValidateInput(input);
        std::cout << DecodeMonth(input[0]) << "/" << DecodeDay(input[1]) << DecodeDay(input[2]) << "/" << DecodeYear(input[3]) << std::endl;
    } catch (std::invalid_argument &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
