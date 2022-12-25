#include <stdio.h>
#include <stdlib.h>
#define NUMBER_TO_SEARCH 7

int binarySearch(int* array, size_t size, int elem);
int printSubArray(int* array, size_t estremoPrimo, size_t estremoSecondo, size_t size);
int comparisons = 1;

int main(int argc, char** argv) {
    printf("\033[1;31m#ESTREMI \033[1;34m#META' ARRAY \033[1;32m#SUB-ARRAY\033[0m\nELEMENTO CERCATO = %d\n", NUMBER_TO_SEARCH);
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
    size_t size = sizeof(array)/4;
    printf("Binary Search Output = %d\n", binarySearch(array, size, NUMBER_TO_SEARCH));
    return 0;
}

int binarySearch(int* array, size_t size, int elem) {
    int estremoA = 0;
    int estremoB = size - 1;
    int mid = 0;
    while(array[(estremoA + estremoB)/2] != elem) {
        printSubArray(array, estremoA, estremoB, size);
        comparisons++;
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
    printf("[debug]: found %d\n[debug]: %d comparisons\n", array[(estremoA + estremoB)/2], comparisons);
    return 0;
}
// ATTENZIONE *******************************************************************************************
// RISCHIO DI MAL DI TESTA OLTRE QUESTO PUNTO **********************************************************
// Nota: L'evidenziazione dell'array funziona male[o funziona bene, non ne ho idea].

int printSubArray(int* array, size_t estremoPrimo, size_t estremoSecondo, size_t size) {
    printf("[ ");
    for(size_t i = 0; i < size; ++i) {
        if(i >= estremoPrimo && i <= estremoSecondo) {
            if(i == estremoPrimo || i == estremoSecondo) {
                printf("\033[1;31m %d \033[0m", array[i]);
            } else {
                if(i == (estremoPrimo + estremoSecondo) / 2) {
                    printf("\033[1;34m %d \033[0m", array[i]);
                } else {
                    printf("\033[1;32m %d \033[0m", array[i]);
                }
            }
        } else {
            printf(" %d ", array[i]);
        }
    }
    printf(" ]\n");
    return 0;
}