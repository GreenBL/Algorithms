#include <stdio.h>
#include <stdlib.h>
#include "../Implementazioni/src/BinarySearch/BinarySearch.h"
#define NUMBER_TO_SEARCH 7

int main(int argc, char** argv) {
    printf("\033[1;31m#ESTREMI \033[1;34m#META' ARRAY \033[1;32m#SUB-ARRAY\033[0m\nELEMENTO CERCATO = %d\n", NUMBER_TO_SEARCH);
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    size_t size = sizeof(array)/4;
    printf("Binary Search Output = %d\n", binarySearch(array, size, NUMBER_TO_SEARCH));
    return 0;
}
