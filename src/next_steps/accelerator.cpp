#include <iostream>

void accelerate(int& speed, int amount) {
    speed += amount;
}

int main() {
    int speed = 10;
    int accelerateBy = 5;

    std::cout << "Staring speed: " << speed << std::endl;
    accelerate(speed, accelerateBy);
    std::cout << "New speed: " << speed << std::endl;
    return 0;
}
