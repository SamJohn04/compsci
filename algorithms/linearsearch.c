#include <stdio.h>

int search(int[], int, int);

int main(void) {
    int size, key;
    int i, position, _;

    printf("Length of array: ");
    _ = scanf("%d", &size);
    int array[size];

    printf("Integers in the array:\n");
    for (i = 0; i < size; i++) {
        _ = scanf("%d", array + i);
    }

    printf("Key value to search for: ");
    _ = scanf("%d", &key);

    position = search(array, size, key);
    if (position > -1) {
        printf("Key element found in %d\n", position);
    } else {
        printf("Key element not found.\n");
    }

    return 0;
}

int search(int array[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}