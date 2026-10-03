#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    int* result = (int*)calloc(queries_count, sizeof(int));
    *result_count = queries_count;

    for (int i = 0; i < queries_count; i++) {
        for (int j = 0; j < stringList_count; j++) {
            if (strcmp(queries[i], stringList[j]) == 0) {
                result[i]++;
            }
        }
    }

    return result;
}

int main(void) {
    int stringList_count;
    if (scanf("%d", &stringList_count) != 1) return 1;

    char** stringList = (char**)malloc(stringList_count * sizeof(char*));
    for (int i = 0; i < stringList_count; i++) {
        stringList[i] = (char*)malloc(21 * sizeof(char));
        scanf("%20s", stringList[i]);
    }

    int queries_count;
    if (scanf("%d", &queries_count) != 1) return 1;

    char** queries = (char**)malloc(queries_count * sizeof(char*));
    for (int i = 0; i < queries_count; i++) {
        queries[i] = (char*)malloc(21 * sizeof(char));
        scanf("%20s", queries[i]);
    }

    int result_count = 0;
    int* result = matchingStrings(stringList_count, stringList, queries_count, queries, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    for (int i = 0; i < stringList_count; i++) {
        free(stringList[i]);
    }
    free(stringList);

    for (int i = 0; i < queries_count; i++) {
        free(queries[i]);
    }
    free(queries);
    free(result);

    return 0;
}