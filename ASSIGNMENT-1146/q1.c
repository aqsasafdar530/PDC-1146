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
int main() {
    // Allocate memory for the array
    int *array = (int *)malloc(sizeof(int) * ARRAY_SIZE);
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Initialize array with random numbers
    initialize_array(array, ARRAY_SIZE);

    // Variables to store total execution time and result
    double total_time = 0.0;
    long long result = 0;

    printf("Sequential Array Sum over %d runs:\n", NUM_RUNS);
        // Perform the sum NUM_RUNS times and measure execution time
        for (int run = 0; run < NUM_RUNS; run++) {
            clock_t start = clock(); // Start timing
    
            result = sequential_sum(array, ARRAY_SIZE); // Sequential sum calculation
    
            clock_t end = clock();   // End timing
            double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
            total_time += time_taken;
    
            printf("Run %d: Sum = %lld, Time = %f seconds\n", run + 1, result, time_taken);
        }
    
        // Calculate and print the average execution time
        double avg_time = total_time / NUM_RUNS;
        printf("\nAverage execution time over %d runs: %f seconds\n", NUM_RUNS, avg_time);
    
        free(array); // Free the allocated memory
        return 0;
    }
    

