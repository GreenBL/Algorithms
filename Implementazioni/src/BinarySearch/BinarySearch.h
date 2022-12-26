#include <stdio.h>
#include <stdlib.h>
#include "../../../Utility/PrintSubArray.h"

int binarySearch(int* array, size_t size, int elem) {
    int estremoA = 0;
    int estremoB = size - 1;
    int mid = 0;
    while(array[(estremoA + estremoB)/2] != elem) {
        printSubArray(array, estremoA, estremoB, size);
        mid = (estremoA + estremoB)/2;
        if(array[mid] > elem) {
            estremoB = mid - 1;
        } else {
            estremoA = mid + 1;
        }
        if(estremoA > estremoB) {
            return 1;
        }
    }
    printSubArray(array, estremoA, estremoB, size);
    printf("[debug]: found %d\n", array[(estremoA + estremoB)/2]);
    return 0;
}
