#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int subarrayBitwiseORs(int* arr, int arrSize) {
    int* results = (int*)malloc(arrSize * 32 * sizeof(int));
    int totalCount = 0;
    int leftBound = 0; 
    for (int i = 0; i < arrSize; i++) {
        int rightBound = totalCount; 
        results[totalCount++] = arr[i];
        for (int j = leftBound; j < rightBound; j++) {
            int newOrValue = results[j] | arr[i];
            if (results[totalCount - 1] != newOrValue) {
                results[totalCount++] = newOrValue;
            }
        }
        leftBound = rightBound;
    }
    qsort(results, totalCount, sizeof(int), compare);
    int uniqueCount = (totalCount > 0) ? 1 : 0;
    for (int i = 1; i < totalCount; i++) {
        if (results[i] != results[i - 1]) {
            uniqueCount++;
        }
    }
    
    free(results);
    return uniqueCount;
}
