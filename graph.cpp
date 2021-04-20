#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "heap.h"

extern VERTEX *V;
void printPath(int n, int source, int destination, int s, int t) {
    PATH *pPATH;
    PATH *pNode;
    int u, v;
    if (V[t].color == 0) {
        if (destination < 1 || destination > n || t == destination) {
            printf("No %d-%d path exists.\n", s, t);
            return;
        }
        else {
            printf("No %d-%d path has been computed.\n", s,t);
            return;
        }
    }
    else if (V[t].color == 1) {
        printf("Path not known to be shortest: <%d", s);
    }
    else if (V[t].color == 2) {
        printf("Shortest path: <%d", s);
    }
    //push onto stack
    pNode = (PATH *) malloc(sizeof(PATH));
    pNode->vertex =t;
    pNode->next = NULL;
    pPATH = pNode;
    v = pNode->vertex;
    while (V[v].pi) {
        u = V[v].pi;
        pNode = (PATH *) malloc(sizeof(PATH));
    }
}

int dijkstra(int n, pNODE *A, int s, int t, int flag) {
    pNODE node;
    HEAP *heap;
    ELEMENT *element;
    int u,v,i;
    float w;
    int pos;
    int count_Heapify;
    
    for (i=1; i<=n; i++) {
        V[i].color = 0;
        V[i].pi = 0;
    }
    V[s].dist = 0;
    V[s].color = 1;

    heap = Initialize(n);
    element = (ELEMENT *) malloc(sizeof(ELEMENT));
    element->vertex = s;
    element->key = 0;
    HeapInsert(heap, element);
    if (flag == 1) {
        //print insertion info
        printf("Insert vertex %d, key = %12.4f\n", element->vertex, element->key);
    }
    while (heap->size) {
        element = DeleteMin(heap, &flag, &count_Heapify);
        if (flag == 1) {
            //print deletion
            printf("Delete vertex %d, key=%12.4f\n", element->vertex, element->key);
        }
        u = element->vertex;
        V[u].color = 2;
        if (element->vertex == t){
            break;
        }
        free(element);
        node = A[u];
        while (node) {
            v = node->v;
        }
    }

}