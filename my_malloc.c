#include "my_malloc.h"
#include <stdio.h>

static Header base[MALLOC_SIZE];
static Header *freep = NULL;
static void* pointers[MALLOC_SIZE];
static int lastindex = 0;
static void enlistpointer(void*);
static int delistpointer(void*);
static int findpointer(void*);

void *my_malloc(unsigned nbytes, char *file, int line) {
    Header *p, *prevp;
    unsigned nunits;

    nunits = (nbytes+sizeof(Header)-1)/sizeof(Header)+1;
    if ((prevp = freep) == NULL) {
        base->s.succ = freep = prevp = base;
        base->s.size = MALLOC_SIZE;
    }
    for (p = prevp->s.succ; ; prevp = p, p = p->s.succ) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits) {
                if (p == p->s.succ) {   //last free block
                    printf("my_malloc Error: Ran out of memory at %s, line %d\n", file, line);
                    return NULL;
                } 
                prevp->s.succ = p->s.succ;
            }
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            enlistpointer(p+1);
            return (void *) (p+1);
        }
        if (p == freep) {
            printf("my_malloc Error: Ran out of memory at %s, line %d\n", file, line);
            return NULL;
        }
    }
}

void my_free(void *ap, char *file, int line) {
    if (!findpointer(ap)) {
        printf("my_free Error: Invalid free at %s, line %d\n", file, line);
        return;
    }
    Header *bp, *p;
    
    bp = (Header *) ap - 1;
    for (p = freep; !(bp > p && bp < p->s.succ); p = p->s.succ)
        if (p >= p->s.succ && (bp > p || bp < p->s.succ))
            break;

    if (bp + bp->s.size == p->s.succ) {
        bp->s.size += p->s.succ->s.size;
        bp->s.succ = p->s.succ->s.succ;
    } else
        bp->s.succ = p->s.succ;
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.succ = bp->s.succ;
    } else
        p->s.succ = bp;
    freep = p;
    delistpointer(ap);
}

static void enlistpointer(void* p) {
   int i;
   for (i = 0; pointers[i] != NULL; ++i)
       ;
   pointers[i] = p;
   if (lastindex < i)
       lastindex = i;
}

static int delistpointer(void* p) {
    int i;
    for (i = 0; i <= lastindex && pointers[i] != p; ++i)
        ;
    if (i > lastindex)
        return 0;
    pointers[i] = NULL;
    if (i == lastindex)
        --lastindex;
    return 1;
}

static int findpointer(void* p) {
    if (p == NULL)
        return 0;
    int i;
    for (i = 0; i <= lastindex; ++i) {
        if (pointers[i] == p)
            return 1;
    }
    return 0;
}
