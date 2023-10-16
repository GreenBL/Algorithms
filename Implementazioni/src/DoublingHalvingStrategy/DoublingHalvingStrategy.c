#include <stdio.h>
#include <stdlib.h>

size_t size;

int main(int argc, char* []argv) {
    int array[] = {0, 1, 2, 3, 4};
    
}

int realloc(int array[], size_t h) {
    size = sizeof(array)/4;
    if(size > h) {
        realloc(array, size * 4);
    }
    if(size <= h/4) {
        realloc(array, size / 2);
    }

    return 0;
}