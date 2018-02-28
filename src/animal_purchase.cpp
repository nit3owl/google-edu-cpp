#include <stdio.h>

int main() {
    for (int h = 0; h < 100; h++) {
        for (int p = 0; p < 100; p++) {
            for (int r = 0; r < 100; r++) {
                if((h * 10) + (p * 3) + (r * .5) == 100)
                    printf("Solution: %d horses, %d pigs, %d rabbits\n", h, p, r);
            }
        }
    }
    return 0;
}
