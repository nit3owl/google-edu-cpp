#include <iostream>
#include <unordered_map>

std::unordered_map<char, std::string> printFormat;

void populateCharacterMap() {
    printFormat['a'] = "  A  \n A A \nA   A\nAAAAA\nA   A\n";
    printFormat['b'] = "BBBB \nB   B\nBBBB \nB   B\nBBBBB\n";

    printFormat['h'] = "H   H\nH   H\nHHHHH\nH   H\nH   H\n";

    printFormat['l'] = "L    \nL    \nL    \nL    \nLLLLL\n";
}

int main() {
    populateCharacterMap();

    std::cout << "Enter a word to print (I can only print the letters 'a', 'b', 'h', 'l'): ";

    std::string word;

    if(!(std::cin >> word)) {
        std::cout << "Something went wrong; exiting.";
        return 1;
    }

    for(int i = 0; i < word.length(); i++) {
        auto it = printFormat.find(word[i]);
        if(it != printFormat.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "'" << word[i] << "' is not a supported character; exiting." << std::endl;
            return 1;
        }
    }

    return 0;
}
  