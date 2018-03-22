#include <iostream>

const int kSize = 3;

void Print(int arr[kSize][kSize][kSize]);

int main() {
    int arr[kSize][kSize][kSize];

    for(int i = 0; i < kSize; i++) {
        for(int j = 0; j < kSize; j++) {
            for(int k = 0; k < kSize; k++) {
                arr[i][j][k] = i + j + k;
            }
        }
    }

    Print(arr);

    return 0;
}

void Print(int arr[kSize][kSize][kSize]) {
     for(int i = 0; i < kSize; i++) {
         std::cout << "[" << std::endl;
        for(int j = 0; j < kSize; j++) {
            std::cout << " [";
            for(int k = 0; k < kSize; k++) {
                std::cout << " " << arr[i][j][k] << " ";
            }
            std::cout << "]" << std::endl;
        }
        std::cout << "]" << std::endl;
    }
}
