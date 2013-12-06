#include "my_malloc.h"
#include <stdio.h>

int main() {

    printf("Size of char, int, float, double, Header is %d, %d, %d, %d\n", sizeof(char), sizeof(int), sizeof(float), sizeof(Header));
    int *x = malloc(200*sizeof(int));
    free(x);

}
