#include <iostream>
#include <ctime>

void calculateConseqIntSums() {
    long previousSum = 1;
    for(long i = 2; i < 2000; i++) {
        long square = i*i;
        for(long j = previousSum; j < square/2; j++) {
            long sum = (j * (j+1)) / 2;
            if (sum == square) {
                previousSum = j;
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

    return 0;
}