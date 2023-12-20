#include <stdlib.h>
#include "graph.h"

AdjacencyMatrix *AdjacencyMatrixInit(int vertices) {
    AdjacencyMatrix *adjMatrix;
    int **matrix;

    if (vertices <= 0) {
        return NULL;
    }

    adjMatrix = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    if (adjMatrix == NULL) {
        return NULL;
    }

    matrix = (int **)malloc(vertices*sizeof(int *));
    if (matrix == NULL) {
        free(adjMatrix);
        return NULL;
    }

    for (int i=0; i<vertices; i++) {
        matrix[i] = (int *)malloc(vertices*sizeof(int));

        if (matrix[i] == NULL) {
            for (int j=i-1; j>0; j--) {
                free(matrix[j]);
                return NULL;
            }
        }
    }

    adjMatrix->matrix = matrix;
    adjMatrix->vertices = vertices;

    // Inizializzazione della matrice con zeri
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjMatrix->matrix[i][j] = 0;
        }
    }

    return adjMatrix;
}

Graph *graphInit(int vertices) {
    Graph *graph;
    AdjacencyMatrix *adjMatrix;
    Node **nodeVector;

    if (vertices <= 0) {
        return NULL;
    }

    adjMatrix = AdjacencyMatrixInit(vertices);

    nodeVector = (Node **)malloc(vertices*sizeof(Node *));
    if (nodeVector == NULL) {
        //DistruttoreAdjMatrix(adjMatrix);
        return NULL;
    }

    for (int i=0; i<vertices; i++) {
        nodeVector[i] = (Node *)malloc(sizeof(Node));

        if (nodeVector[i] == NULL) {
            for (int j=i-1; j>0; j--) {
                free(nodeVector[j]);
                return NULL;
            }
        }
    }

    // Inizializzazione dei nodi con puntatori a funzione nulli
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            nodeVector[i]->vertexIndex = i;
            nodeVector[i]->operation = NULL;
        }
    }

    graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL) {
        //DistruttoreAdjMatrix(adjMatrix);
        //DistruttoreNode(node);
        return NULL;
    }

    graph->adjMatrix = adjMatrix;
    graph->nodeVector = nodeVector;

    return graph;
}

int insertNode(Graph *graph, Node *node) {
    if (node == NULL) {
        return -1;
    }

    //operazioni m emoria
}