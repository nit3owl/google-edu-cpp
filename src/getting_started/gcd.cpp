#include <iostream>

int gcd(int x, int y) {
    int remainder;
    while(y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

int main() {
    int x, y;

    std::cout << "Enter two numbers: " << std::endl;

    if(!(std::cin >> x >> y)) {
        std::cerr << "Must enter two numbers." << std::endl;
        return 1;
    }

    std::cout << "Greatest common divisor of " << x << " and " << y << " is " << gcd(x, y) << std::endl;

    return 0;
}
