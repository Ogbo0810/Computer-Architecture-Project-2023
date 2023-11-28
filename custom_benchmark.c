#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITERATIONS 1000

// Recursive function with nested loops for branching
int complexRecursiveFunction(int depth) {
    int result = 0;

    if (depth > 0) {
        for (int i = 0; i < depth; ++i) {
            if (i % 2 == 0) {
                result += complexRecursiveFunction(depth - 1);
            } else {
                result -= complexRecursiveFunction(depth - 1);
            }
        }
    }

    return result;
}

// Workload function that calls the complexRecursiveFunction
void complexWorkload() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        int result = complexRecursiveFunction(5);
        // Use the result to prevent the loop from being optimized away
        printf("Result: %d\n", result);
    }
}

int main() {
    clock_t start, end;
    double cpu_time_used;

    // Record the start time
    start = clock();

    // Run the workload with complex branching
    complexWorkload();

    // Record the end time
    end = clock();

    // Calculate the CPU time used
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the execution time
    printf("Execution Time: %f seconds\n", cpu_time_used);

    return 0;
}
