#ifndef _graph_h
#define _graph_h 1

#include <stdio.h>

typedef struct TAG_VERTEX{
    int vertex;
    int color; // color of vertex 0-2
    int pi; // predecessor
    float dist; //current distance from source vertex
    float key;
    int pos; //position in heap array
    char *name; //name of the POI represented by this vertex
}VERTEX;
typedef VERTEX *pVERTEX;

typedef struct TAG_NODE{
    int u; // start vertex u
    int v; // end vertex v
    float w; //weight of edge u,v
    TAG_NODE *next; //pointer to next node
}NODE;
typedef NODE *pNODE;

typedef struct TAG_PATH{
    int vertex;
    TAG_PATH *next;
}PATH;

void printPath(int n, int source, int destination, int s, int t);
int djikstra(int n, pNODE *A, int s, int t, int flag);

#endif