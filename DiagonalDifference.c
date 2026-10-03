#include <stdio.h>
#include <stdlib.h>

/**
 * Calculates the absolute difference between the sums of a matrix's two diagonals.
 * 
 * @param arr_rows    Number of rows in the matrix
 * @param arr_columns Number of columns in the matrix
 * @param arr         2D array representing the matrix
 * @return            Absolute difference of the diagonal sums
 */
int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primary_sum = 0;
    int secondary_sum = 0;

    for (int i = 0; i < arr_rows; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][arr_rows - 1 - i];
    }

    return abs(primary_sum - secondary_sum);
}

int main(void) {
    int n;

    // Read matrix size
    if (scanf("%d", &n) != 1) {
        return 1;
    }

    // Dynamically allocate memory for 2D array
    int** arr = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    // Read matrix elements from standard input
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Calculate and print result
    int result = diagonalDifference(n, n, arr);
    printf("%d\n", result);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}