#include <stdio.h>
#include <stdlib.h>

int sequentialSearch(int* array, size_t size, int element) {
    for(size_t i = 0; i < size; ++i) {
        if(array[i] == element) {
            return 0;
        }
    }
    return 1;
}