#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000
#define NUM_THREADS 4

int main() {
    int i, j;
    double start, end, time, avg_time = 0.0;
    double sum = 0.0;

    // Allocate memory and initialize array elements
    double *arr = (double *)malloc(N * sizeof(double));
    for (i = 0; i < N; i++) {
        arr[i] = 1.0;
    }

    omp_set_num_threads(NUM_THREADS);
