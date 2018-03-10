#include <iostream>
#include <string>

int *ToDigits(int num) {
    int *digits = new int[3];
    int i = 2;
    while(num > 0) {
        digits[i--] = num % 10;
        num = num / 10;
    }

    return digits;
}

int ToNum(int a, int b, int c) {
    int num = a;
    num += b * 10;
    num += c * 100;

    return num;
}

int CheckAndConvertOdd(int i) {
    if(i % 2 != 0) {
        if(i + 11 < 20) {
            i += 11;
        } else {
            i -= 11;
        }
    }

    return i;
}

int main() {
    int num;
    std::cout << "Enter a three digit number: ";

    if(!(std::cin >> num) || num > 999) {
        std::cout << "Error; exiting." << std::endl;
        return 1;
    }

    int *digits = ToDigits(num);
    
    int abc = ToNum(digits[0], digits[1], digits[2]);
    int bca = ToNum(digits[1], digits[2], digits[0]);
    int cab = ToNum(digits[2], digits[0], digits[1]);

    int x = abc % 11;
    int y = bca % 11;
    int z = cab % 11;

    int xy = x + y;
    int yz = y + z;
    int zx = z + x;

    if(xy == 9 || yz == 9 || zx == 9) {
        std::cout << "Something was 9" << std::endl;
        return 1;
    }

    xy = CheckAndConvertOdd(xy);
    yz = CheckAndConvertOdd(yz);
    zx = CheckAndConvertOdd(zx);

    xy /= 2;
    yz /= 2;
    zx /= 2;

    std::cout << "a: " << xy << ", b: " << yz << ", c: " << zx << std::endl;

    return 0;
}
