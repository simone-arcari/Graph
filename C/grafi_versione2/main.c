#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int funNumber = 4;

void function1(void) {
    printf("Hi, I am function1\n");
}

void function2(void) {
    printf("Hi, I am function2\n");
}

void function3(void) {
    printf("Hi, I am function3\n");
}

void function4(void) {
    printf("Hi, I am function4\n");
}

int main(void) {
    AdjacencyMatrix *graph;

    graph = adjacencyMatrixInit(funNumber);
    if (!graph) {
        perror("Errore allocazione memoria per il grafo");
        return EXIT_FAILURE;
    }

    graph->functionMatrix[0][0] = (void (*)(void *))function1;
    graph->functionMatrix[0][1] = (void (*)(void *))function2;
    graph->functionMatrix[1][0] = (void (*)(void *))function3;
    graph->functionMatrix[1][1] = (void (*)(void *))function4;

    graph->functionMatrix[0][0](NULL);
    graph->functionMatrix[1][1](NULL);
    graph->functionMatrix[0][1](NULL);
    graph->functionMatrix[1][0](NULL);

    deleteAdjacencyMatrix(graph);

    return EXIT_SUCCESS;

}