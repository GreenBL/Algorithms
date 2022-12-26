#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* array, size_t size, int element) {
    if(size == 0) {
        return 1;
    }
    size = size/2;
    if(array[size - 1] == element) {
        printf("[debug]: found %d\n", array[size - 1]);
        return 0;
    } 

    if(array[size - 1] > element) {
        return binarySearch(array, size - 1, element);
    } else {
        return binarySearch(array + size, size + 1, element);
    }
}