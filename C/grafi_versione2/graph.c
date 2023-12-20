#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

AdjacencyMatrix *adjacencyMatrixInit(int vertices) {
    AdjacencyMatrix *graph;
    void (***functionMatrix)(void *param);

    if(vertices <= 0) {
        return NULL;
    }

    graph = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    if (!graph) {
        return NULL;
    }

    functionMatrix = (void***)malloc(vertices * sizeof(void **));
    if (!functionMatrix) {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < vertices; i++) {
        functionMatrix[i] = (void (**)(void*))malloc(vertices * sizeof(void *));
        
        if (!functionMatrix[i]) {
            // Libera la memoria per le righe precedenti in caso di errore
            for (int j = i - 1; j >= 0; j--) {
                free(functionMatrix[j]);
            }

            // Libera la memoria per la matrice
            free(functionMatrix);
            free(graph);

            return NULL;
        }

        // Inizializzo i puntatori a funzione a NULL
        for (int j = 0; j < vertices; j++) {
            functionMatrix[i][j] = NULL;
        }
    }

    graph->vertices = vertices;
    graph->functionMatrix = functionMatrix;

    return graph;
}
