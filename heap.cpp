// heap implementation
#include <stdio.h>
#include <cmath>
#include "heap.h"

int minheaps,extracted;
extern VERTEX *V;
void heapFree(HEAP *heap) {
    free(heap->H);
    free(heap);
}
HEAP * Initialize(int n) {
    HEAP *heap = new HEAP;
    heap->capacity = n;
    heap->size = 0;
    //dynamic memory allocation
    heap->H = new ELEMENT * [n+1];
    for (int i = 0; i< n+1;i++) {
        heap->H[i] = new ELEMENT{0};
    }
    return heap;      
}

void printHeap(HEAP heap) {
    printf("capacity=%d, size=%d\n",heap.capacity,heap.size);
    if (heap.size == 0) {
        return;
    }
    for (int j = 0; j < heap.size; j++) {
        printf("%f",heap.H[j]->key);
        if (j != heap.size - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
}

HEAP * buildHeap(HEAP * heap) {
    minheaps = -1;
    ELEMENT** A = heap->H;
    for (int i = ((heap->size)/2) +1; i>0; i--) {
        A = minHeapify(heap,i);
    }
    heap->H = A;
    return heap;
}

ELEMENT** minHeapify(HEAP * heap, int i) {
    ELEMENT** A = heap->H;
    minheaps++;
    int smallest,l,r;
    l = LEFT(i);
    r = RIGHT(i);
    if ((l <= heap->size) && (A[l-1]->key < A[i-1]->key)) {
        smallest = l;
    }
    else {
        smallest = i;
    }
    if ((r <= heap->size) && (A[r-1]->key < A[smallest-1]->key)) {
        smallest = r;
    }
    if (smallest != i) {
        int swap = A[i-1]->key;
        A[i-1]->key = A[smallest-1]->key;
        A[smallest-1]->key = swap;
        heap->H = A;
        A = minHeapify(heap, smallest);
    }
    return A;
} 


int HeapInsert(HEAP *heap, pELEMENT item) {
    if (heap->size >= heap->capacity) {
        printf("Error in HeapInsert: Heap full...\n");
        return 1;
    }
    heap->size++;
    heap->H[heap->size] = item;
    heap->H[heap->size]->pos = heap->size;

    MovingUp(heap, heap->size);
    return 0;
}

int DecreaseKey (HEAP *heap, int pos, float newKey) {
    if (pos < 1 || pos > heap->size || newKey >= heap->H[pos]->key) {
        return 1;
    }

    heap->H[pos]->key = newKey;
    MovingUp(heap, pos);
    return 1;
}

void MovingUp (HEAP *heap, int pos) {
    pELEMENT temp;
    int parent;
    parent = pos/2;
    if (pos > 1 && heap->H[pos]->key < heap->H[parent]->key) {
        temp = heap->H[pos];
        heap->H[pos] = heap->H[parent];
        heap->H[parent]= temp;
        heap->H[pos]->pos = pos;
        heap->H[parent]->pos = parent;
        MovingUp(heap, parent);
    }
}
pELEMENT DeleteMin(HEAP *heap, int *flag, int *count_Heapify) {
    pELEMENT min, last;
    if (heap->size <=0) {
        printf("Error in DeleteMin: heap empty\n");
        return NULL;
    }
    min = heap->H[1]; 
    last = heap->H[heap->size--];
    heap->H[1] = last;
    V[heap->H[1]->vertex].pos =1;
    minHeapify(heap,1);
    V[min->vertex].pos = 0;
    return min;

}
int minHeapCount() {
    return minheaps;
}

int extractedKey() {
    return extracted;
}