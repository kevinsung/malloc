#include "my_malloc.h"
#include <stdio.h>

void main() {

    //printf("Size of char, int, float, double, Header is %d, %d, %d, %d, %d\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double), sizeof(Header));

    char *a = malloc(32704*sizeof(char));
    int *b = malloc(4096*sizeof(int));
    float *c = malloc(2048*sizeof(float));
    double *d = malloc(1022*sizeof(double));    /*malloc is now out of space*/

    int i = 0;

    char *e = malloc(80000*sizeof(char));

    free(a);
    free(b);
    free(c);
    free(d);

}
