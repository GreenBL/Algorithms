#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* array, size_t size, int element) {
    printf("[debug]: called funct array[size/2] = %d, size = %lu\n, subarray[%d-%d]\n", array[size/2], size, array[0], array[size - 1]);
    if(size == 0) {
        return 1;
    }
    if(array[size/2] == element) {
        printf("[debug]: found %d\n", array[size/2]);
        return 0;
    } 

    if(array[size/2] > element) {
        return binarySearch(array, (size/2) - 1, element);
    } else {
        return binarySearch(array + (size/2), (size/2) + 1, element);
    }
}