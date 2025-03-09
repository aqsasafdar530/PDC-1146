#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 100000000  // Size of the array
#define NUM_RUNS 10           // Number of runs to compute average execution time

// Function to initialize array with random numbers
void initialize_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random number between 0-99
    }
}

// Function to compute the sum sequentially
long long sequential_sum(int *arr, int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
