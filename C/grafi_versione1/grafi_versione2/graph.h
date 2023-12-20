#ifndef GRAPH_H_
#define GRAPH_H_

// Definizione della struttura del nodo
typedef struct Node {
    int vertexIndex;                    // Indice del vertice
    void (*operation)(void *param);     // Puntatore a funzione
} Node;

// Definizione della struttura per la matrice di adiacenza
typedef struct AdjacencyMatrix{
    int **matrix;  // Puntatore alla matrice
    int vertices;  // Numero di vertici nel grafo
} AdjacencyMatrix;

// Definizione della struttura del grafo
typedef struct Graph {
    AdjacencyMatrix *adjMatrix;
    Node **nodeVector;
} Graph;

AdjacencyMatrix *adjacencyMatrixInit(int vertices);     // Crea una matrice di adiacenza inizializzata a zero
Graph *graphInit(int vertices);                         // Crea un grafo vuoto
int insertNode(Graph *graph, Node *node);                             // Inserisci il nodo u
insertEdge(u,v);                        // Inserisci l’arco (u,v)
deleteNode(u)                           // Cancella il nodo u
deleteEdge(u,v)                         // Cancella l’arco (u,v)
adj(u)                                  // Restituisce l’insieme dei nodi adiacenti a u
V()                                     // Restituisce l’insieme di tutti i nodi.

#endif  /* GRAPH_H_ */