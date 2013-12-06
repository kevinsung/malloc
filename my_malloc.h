#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define malloc(x) my_malloc(x, __FILE__, __LINE__)
#define free(x) my_free(x, __FILE__, __LINE__)

#define MALLOC_SIZE 4096

typedef long Align;

union Header {
    struct {
        union Header *succ;
        unsigned size;
    } s;
    Align x;
};

typedef union Header Header;

void *my_malloc(unsigned nbytes, char *file, int line);
void my_free(void *ap, char *file, int line);

#endif
