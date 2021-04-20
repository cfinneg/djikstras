//heap header file
#ifndef HEAP_H_
#define HEAP_H_

#define PARENT(x) (x/2)
#define LEFT(x) (2*x)
#define RIGHT(x) ((2*x) + 1)

#include "graph.h"

typedef VERTEX ELEMENT;

typedef VERTEX *pELEMENT;

typedef struct TAG_HEAP{
    int capacity; /* max size of the heap */
    int size; /* current size of the heap */
    pELEMENT *H; /* pointer to pointers to elements */
}HEAP;

void heapFree(HEAP *heap);
HEAP * Initialize(int n);
void printHeap(HEAP heap);
HEAP * buildHeap(HEAP * heap);
ELEMENT** minHeapify(HEAP * heap, int i);
int minHeapCount();
HEAP * extractMin(HEAP * heap);
int extractedKey();
int HeapInsert(HEAP * heap, ELEMENT * e);
int DecreaseKey (HEAP *heap, int pos, float newKey);
void MovingUp (HEAP *heap, int pos);
pELEMENT DeleteMin(HEAP *heap, int *flag, int *count_Heapify);

#endif
