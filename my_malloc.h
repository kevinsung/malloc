#if !defined(MY_MALLOC_H)
#define MY_MALLOC_H

#define MALLOC_SIZE 8192

void *my_malloc(int size);
void my_free(void *p);

struct MemEntry
{
	struct MemEntry *succ;
	struct MemEntry *prev;
	int size;
	unsigned char *buffer;
};

#endif
