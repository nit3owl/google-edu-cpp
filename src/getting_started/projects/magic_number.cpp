#include <iostream>
#include <string>

int Reverse(int num) { 
    int reversed = 0;
    int power = 100;
    while(num > 0) {
        reversed += (num % 10) * power;
        num = num / 10;
        power = power / 10;
    }

    return reversed;
}

int main(){
    std::cout << "Enter a number three digit integer whose first digit is greater than its last: ";

    int num;
    if(!(std::cin >> num) || num > 999) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int reversed = Reverse(num);

    std::cout << "reverse it: " << std::to_string(reversed) << std::endl;

    int temp = num - reversed;

    std::cout << "subtract: " << std::to_string(num) << " - " << std::to_string(reversed) << " = " << std::to_string(temp) << std::endl;

    num = temp;
    reversed = Reverse(temp);
    std::cout << "reverse it: " << std::to_string(reversed) << std::endl;

    temp = num + reversed;

    std::cout << "add: " << std::to_string(reversed) << " + " << std::to_string(num) << " = " << std::to_string(temp) << std::endl;

    return 0;
}
