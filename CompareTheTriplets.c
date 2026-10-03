#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = 0; // Alice's score
    result[1] = 0; // Bob's score
    *result_count = 2;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            result[0]++;
        } else if (a[i] < b[i]) {
            result[1]++;
        }
    }

    return result;
}

int main(void) {
    int a[3];
    int b[3];

    for (int i = 0; i < 3; i++) {
        if (scanf("%d", &a[i]) != 1) return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (scanf("%d", &b[i]) != 1) return 1;
    }

    int result_count = 0;
    int* result = compareTriplets(3, a, 3, b, &result_count);

    printf("%d %d\n", result[0], result[1]);

    free(result);
    return 0;
}