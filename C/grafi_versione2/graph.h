#ifndef GRAPH_H_
#define GRAPH_H_

// Definizione della struttura per la matrice di adiacenza
typedef struct AdjacencyMatrix{
    void (***functionMatrix)(void *param);  // Puntatore alla matrice di puntatori a funzione
    int vertices;                          // Numero di vertici nel grafo
} AdjacencyMatrix;


AdjacencyMatrix *adjacencyMatrixInit(int vertices);     // Crea una matrice di adiacenza inizializzata a zero
void deleteAdjacencyMatrix(AdjacencyMatrix *graph);      // Dealloca tutta la memoria


/*int insertNode(Graph *graph, Node *node);                             // Inserisci il nodo u
insertEdge(u,v);                        // Inserisci l’arco (u,v)
deleteNode(u)                           // Cancella il nodo u
deleteEdge(u,v)                         // Cancella l’arco (u,v)
adj(u)                                  // Restituisce l’insieme dei nodi adiacenti a u
V()                                     // Restituisce l’insieme di tutti i nodi.
*/
#endif  /* GRAPH_H_ */