#include <stdio.h>


int main() {

    int *x = my_malloc(200*sizeof(int), __FILE__, __LINE__);
    my_free(x);

}
