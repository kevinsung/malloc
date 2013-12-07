#include "my_malloc.h"
#include <stdio.h>

void main() {

    //printf("Size of char, int, float, double, Header is %d, %d, %d, %d, %d\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double), sizeof(Header));
   // 4096 and 65536 total bytes

    char *a = malloc(sizeof(char));
    free(a);
    a = malloc(sizeof(char));
    free(a);
    //int *b = malloc(1000*sizeof(int));
    //free(b);
    /*int *b = malloc(4096*sizeof(int));
    float *c = malloc(2048*sizeof(float));
    double *d = malloc(1022*sizeof(double));  /*malloc is now out of space*/
    //char *e = malloc(sizeof(char));
      
    /*int i;
    for (i = 0; i < 1022; ++i) {
        *(a+i) = 'a' + (i % 26);
        *(b+i) = i;
        *(c+i) = 3.14 + i;
        *(d+i) = 2.718 + i;
    }
    *(a+i) = '\0';
    printf("%s\n", a);
    printf("%d\n", *(b+256));
    printf("%f\n", *(c+314));
    printf("%f\n", *(d+278));

    free(a+10);
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(i);

    int *f;
    free(f);
    */

}
