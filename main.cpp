#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include "util.h"
#include "heap.h"
#include "graph.h"

VERTEX *V;
int main(int argc, char *argv[])
{

    FILE *ifile;
    pNODE *A;
    pNODE node;
    char word[256];
    char word2[256];
    int directed,n,m,i,s,s_new,t,t_new,source,source_new,destination,destination_new,u,v,edge_id,flag,flag_new;
    float w;
    int v_scanf,v_fscanf;
    int r_value;
    // command line
    char * filename = argv[1];
    char * direction = argv[2];
    if (0 == strcmp(direction,"directed\0")) {
        directed = 1;
    }
    else {
        directed = 0;
    }
    //read in graph and construct adjacency list
    ifile = fopen(filename, "r");
    v_fscanf = fscanf(ifile, "%d%d", &n, &m);
    // allocate memory for adjacency list
    A = (pNODE *) calloc(n+1,sizeof(pNODE));
    if (!A) {
        printf("Error: calloc failure.\n");
        exit(1);
    }
    // construct list
    for (i = 1; i<=m;i++) {
        v_fscanf = fscanf(ifile, "%d%d%d%f", &edge_id, &u, &v, &w);
        node = (pNODE) malloc(sizeof(NODE));
        if(!node) {
            printf("Error: malloc failure.\n");
        }
        node->u = u;
        node->v = v;
        node->w = w;
        node->next = A[u];
        A[u] = node;
        // for undirected graph
        if (!directed) {
            node = (pNODE) malloc(sizeof(NODE));
            if (!node) {
                printf("Error: malloc failure.\n");
                exit(1);
            }
            node->u = v;
            node->v = u;
            node->w = w;
            node->next = A[v];
            A[v] = node;
        }
    }
    fclose(ifile);
    source = 0;
    destination = 0;
    V = (VERTEX *) calloc(n+1, sizeof(VERTEX));

    // begin queries
    while (1) {
        r_value = nextWord(word);

        // stop query
        if (0 == strcmp(word, "stop")){
            printf("Query: %s\n", word);
            break;
        }
        // find query
        if (0 == strcmp(word, "find")) {
            v_scanf = scanf("%d%d%d", &source_new, &destination_new, &flag_new);
            printf("Query: %s %d %d %d\n", word, source_new, destination_new, flag_new);
            if (source_new < 1 || source_new > n || flag_new <0 || flag_new > 1) {
                printf("Error: invalid find query\n");
            }
            else {
                source = source_new;
                destination = destination_new;
                flag = flag_new;
                dijkstra(n, A, source, destination, flag);
            }
        }
        else if (0 == strcmp(word, "write")) {
            r_value = nextWord(word2);
            if (0 == strcmp(word2, "path")){
                v_scanf = scanf("%d%d", &s_new, &t_new);
                printf("Query: %s %s %d %d\n", word, word2, s_new, t_new);
                if (source == 0) {
                    printf("Error: no path computation done\n");
                }
                else if (s_new != source || t_new == s_new || t_new <1 || t_new > n) {
                    printf("Error: invalid source destination pair\n");
                }
                else{
                    s = s_new;
                    t= t_new;
                    printPath(n, source, destination, s, t);
                }
            }
        }
    }

    
    
    return(0);
}

