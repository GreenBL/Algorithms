#include <stdio.h>
#include <stdlib.h>

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