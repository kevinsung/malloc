#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define malloc(x) my_malloc(x, __FILE__, __LINE__)
#define free(x) my_free(x, __FILE__, __LINE__)

#endif
