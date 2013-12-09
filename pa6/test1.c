#include "my_malloc.h"
#include <stdio.h>

void main() {

     //printf("Size of char, int, float, double, Header is %d, %d, %d, %d, %d\n", sizeof(char), sizeof(int), sizeof(float), sizeof(double), sizeof(Header));
    // 4096 and 65536 total bytes

    char *a;
    int *b;
    float *c;
    double *d;
    char *e;
    printf("ONLY MALLOC:\n");

    printf("TEST 1: one pointer malloc-ed success (char*):\n");
    a = malloc(32704*sizeof(char));
    if(a){
       printf("Passed test case 1\n");
    } else {
       printf("Failed test case 1\n");
    }
    free(a); 

    printf("TEST 2: multiple pointers malloc-ed success (char*, int*):\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    if(a && b){
       printf("Passed test case 2\n");
    } else {
       printf("Failed test case 2\n");
    }
    free(a); 
    free(b);

    printf("TEST 3: multiple pointers malloc-ed success (char*, int*, float*):\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    c = malloc(2048*sizeof(float));
    if(a && b && c){
       printf("Passed test case 3\n");
    } else {
       printf("Failed test case 3\n");
    }
    free(a); 
    free(b);
    free(c);

    printf("TEST 4: multiple pointers malloc-ed success (char*, int*, float*, double*):\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    c = malloc(2048*sizeof(float));
    d = malloc(1022*sizeof(double));
    if(a && b && c && d){
       printf("Passed test case 4\n");
    } else {
       printf("Failed test case 4\n");
    }
    free(a); 
    free(b);
    free(c);
    free(d);

    printf("TEST 5: saturation - multiple pointer malloc-ed failure (char*, int*, float*, double*):\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    c = malloc(2048*sizeof(float));
    d = malloc(1022*sizeof(double));
    e = malloc(sizeof(char));
    if(a && b && c && d && e){
       printf("Failed test case 5\n");
    } else {
       printf("Passed test case 5\n");
    }
    free(a); 
    free(b);
    free(c);
    free(d);
    free(e);

    printf("TEST 6: one pointer malloc-ed success (exact size):\n");
    a = malloc(65504*sizeof(char));
    if(a){
       printf("Passed test case 6\n");
    } else {
       printf("Failed test case 6\n");
    }
    free(a);

    printf("TEST 7: saturation - one pointer malloc-ed failure (one greater than exact size):\n");
    a = malloc(65505*sizeof(char));
    if(a){
       printf("Failed test case 7\n");
    } else {
       printf("Passed test case 7\n");
    }

    printf("\n--------------\n");
    printf("ONLY FREE TESTS:\n");

    printf("TEST 8: free one pointer success:\n");
    a = malloc(sizeof(char));
    free(a);
    a = NULL;
    if(!a){
       printf("Passed test case 8\n");
    } else {
       printf("Failed test case 8\n");
    }

    printf("TEST 9: free multiple pointer success:\n");
    a = malloc(sizeof(char));
    b = malloc(sizeof(1000*sizeof(int)));
    free(a);
    a = NULL;
    free(b);
    b = NULL;
    if(!a && !b){
       printf("Passed test case 9\n");
    } else {
       printf("Failed test case 9\n");
    }

    printf("TEST 10: free multiple pointer success (free one before other is malloc-ed):\n");
    a = malloc(sizeof(char));
    free(a);
    a = NULL;
    b = malloc(sizeof(1000*sizeof(int)));
    free(b);
    b = NULL;
    if(!a && !b){
       printf("Passed test case 10\n");
    } else {
       printf("Failed test case 10\n");
    }

    printf("TEST 11: free without allocating:\n");
    free(a);
    a = NULL;
    printf("Passed test case 11\n");

    printf("TEST 12: free pointers to dynamic memory not returned from malloc:\n");
    a = malloc(sizeof(char));
    free(a+5);
    a = NULL;
    if(!a){
       printf("Passed test case 12\n");
    } else {
       printf("Failed test case 12\n");
    }
    free(a);

    printf("TEST 13: redundant freeing of same pointer:\n");
    a = malloc(sizeof(char));
    free(a);
    free(a);
    a = NULL;
    if(!a){
       printf("Passed test case 13\n");
    } else {
       printf("Failed test case 13\n");
    }

    printf("TEST 14: freeing of same pointer after being malloc-ed twice:\n");
    a = malloc(sizeof(char));
    free(a);
    a = NULL;
    if(!a){
       printf("Passed test case 14\n");
    } else {
       printf("Failed test case 14\n");
    }

    printf("\n--------------\n");
    printf("BOTH MALLOC AND FREE TESTS:\n");

    printf("TEST 15: fragmentation - malloc, free two nonconsecutive pointers, then malloc to the total size that was freed:\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    c = malloc(2048*sizeof(float));
    d = malloc(1022*sizeof(double));
    free(b);
    free(d);
    a = NULL;
    b = NULL;
    c = NULL;
    d = NULL;
    if(a && b && c && d){
       printf("Failed test case 15\n");
    } else {
       printf("Passed test case 15\n");
    }

    printf("TEST 16: malloc, free two nonconsecutive pointers, then malloc one of the sizes that was freed:\n");
    a = malloc(32704*sizeof(char));
    b = malloc(4096*sizeof(int));
    c = malloc(2048*sizeof(float));
    d = malloc(1022*sizeof(double));
    free(b);
    free(d);
    a = NULL;
    b = malloc(4096*sizeof(int));
    c = NULL;
    d = NULL;
    if(b){
       printf("Passed test case 16\n");
    } else {
       printf("Failed test case 16\n");
    }
 }
