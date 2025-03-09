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
    // Execute parallel region 10 times for averaging
    for (j = 0; j < 10; j++) {
        sum = 0.0;
        start = omp_get_wtime();

        // Parallel loop with dynamic scheduling and reduction on sum
        #pragma omp parallel for reduction(+:sum) schedule(dynamic, 1000)
        for (i = 0; i < N; i++) {
            sum += arr[i];
        }

        end = omp_get_wtime();
        time = end - start;
        avg_time += time;

        printf("Run %d: Sum = %.2f, Time = %f sec\n", j + 1, sum, time);
    }
