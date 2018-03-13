#include <iostream>
#include <ctime>

void calculateConseqIntSums() {
    for(long i = 1; i < 2000; i++) {
        long square = i*i;
        for(long j = 1; j < square/2; j++) {
            long sum = (j * (j+1)) / 2;
            if (sum == square) {
                std::cout << "Match! i = " << i << ", square = " << square << ", sum of 1 - " << j << std::endl;
            }
        }  
    }
}

void calculateConseqIntSumsWithMemo() {
    int *memo = new int[4000000];
    memo[0] = 0;
    for(long i = 1; i < 2000; i++) {
        long square = i*i;
        for(long j = 1; j < square/2; j++) {
            long sum = memo[j - 1] + j;
            memo[j] = sum;
            if (sum == square) {
                std::cout << "Match! i = " << i << ", square = " << square << ", sum of 1 - " << j << std::endl;
            }
        }  
    }
}

int main() {
    std::clock_t start;
    double duration;

    start = std::clock();    
    calculateConseqIntSums();
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Calculation with Gauss took " << duration << " seconds." << std::endl << std::endl;

    start = std::clock();    
    calculateConseqIntSumsWithMemo();
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "Calculation with memoization took " << duration << " seconds." << std::endl;

    return 0;
}