#if !defined(HEADER_H)
#define HEADER_H 

#define MALLOC_SIZE 8192

typedef long Align;

union Header {
    struct {
        union Header *succ;
        unsigned size;
    } s;
    Align x;
};

typedef union Header Header;

#endif
