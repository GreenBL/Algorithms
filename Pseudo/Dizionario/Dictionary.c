#include "dict.h"

int main() {
    Dictionary dict;
    initDictionary(&dict);

    insert(&dict, "apple", 5);
    insert(&dict, "banana", 3);
    insert(&dict, "cherry", 7);
    insert(&dict, "apple", 10);

    delete(&dict, "banana");

    printf("Value of banana: %d\n", search(&dict, "banana"));
    printf("Value of apple: %d\n", search(&dict, "apple"));
    printf("Value of cherry: %d\n", search(&dict, "cherry"));

    return 0;
}