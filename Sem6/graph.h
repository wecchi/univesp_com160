 /* Videoaula 18 -  00:38
  * Usaremos matriz de adjacência para representação do grafo
  */
#ifndef GRAPH_H 
#define GRAPH_H 
    #include "queue.h"
    using namespace std;

    class Graph{
        private:
            int NULL_EDGE;      // Valor de uma constante para respresentar uma aresta nula
            int maxVertex;      // Número máximo de vértices
            int numVertex;      // Número de vértices adicionados
            Vertex *vertexes;   // Array com todos os vértices
            int **edges;        // Matriz de adjacências (ponteiro para ponteiro)
            bool *marks;        // marks[i] marca se o vértice[i] foi visitado
            int getIndex(Vertex);

        public:
            Graph(int max = 50, int null = 0);
            ~Graph();

            void addVertex(Vertex);             // Adiciona um vértice
            void addEdge(Vertex, Vertex, int);  // Adiciona uma aresta com base no par ordenado de (Vertex, Vertex)

            int getWeight(Vertex, Vertex);      // Dada uma aresta retorna o peso
            void getAdjacents(Vertex,Queue&);  // Retorna todos os vértices adjacentes a um dado vértice. Usaremos Queue para criar uma lista de adjacentes
            void clearMarks();
            void markVertex(Vertex);
            bool isMarked(Vertex);
            void printMatrix();
    };
#endif