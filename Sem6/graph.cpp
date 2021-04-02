 /* Videoaula 18 -  07:56
  * Implementação das classes grafo
  */

#include "graph.h"
#include <iostream>
using namespace std;

// Construtor da classe Grafo
Graph::Graph(int max, int null_edge){
    NULL_EDGE = null_edge;
    maxVertex = max;
    numVertex = 0;
    vertexes = new Vertex[maxVertex];
    marks = new bool[maxVertex];
    // Inicializando a 1ª coluna da matriz (cada item da lista aponta para uma lista - linha - de ponteiros do tipo int)
    edges = new int *[maxVertex];
    // Criando as linhas e  colunas da Matriz de adjacências
    for (int row = 0; row < maxVertex; row++){
        edges[row] = new int[maxVertex];
        // Populando a matriz de adjacências com valores que foram definidos como nulos
        for (int col = 0; col < maxVertex; col++)
            edges[row][col] = NULL_EDGE;
    }
}

// Destrutor da classe Grafo
Graph::~Graph(){
    delete [] vertexes;
    delete [] marks;
    for (int row = 0; 0 < maxVertex; row++) // Exclusão das linhas
        delete [] edges[row];
    delete [] edges;    // Exclusão da 1ª coluna
}

// Em vários momentos, pode ser necessário obter o índice de determinado vértice
int Graph::getIndex(Vertex vertex){
    int index = 0;
    string searchName = vertex.getNome();
    while (!(searchName == vertexes[index].getNome())){
        index++;
    }
    return index;    
}

// Para adicionar vértices ou arestas, basta acessa o vetor ou matriz correspondente
void Graph::addVertex(Vertex vertex){
    if (numVertex < maxVertex){
        vertexes[numVertex] = vertex;  //Adiciona um vértice na posição "vaga"
        numVertex++;                   // Incrementa a posição "vaga"
    }
}

void Graph::addEdge(Vertex fromVertex, Vertex toVertex, int weight){
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);
    edges[row][col] = weight;
}

// Aqui iremos retornar o valor que está na matriz de adjacência. Pode-se melhorar no caso de NULL_EDGE (não existe "peso")
int Graph::getWeight(Vertex fromVertex, Vertex toVertex){
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);
    return edges[row][col];
}

// Para obter a lista de adjacentes para um Vértice, usaremos a estrutura FILA
void Graph::getAdjacents(Vertex vertex, Queue &adjVertexes){
    int fromIndex, toIndex = 0;
    fromIndex = getIndex(vertex);
    for (toIndex; toIndex < numVertex; toIndex++)
        if(edges[fromIndex][toIndex] != NULL_EDGE)
            // Uma cópia do elemento é inserida no array
            adjVertexes.enqueue(vertexes[toIndex]);

}

// Métodos para gerenciar marcações ao percorrer a matriz
void Graph::clearMarks(){
    for (int i = 0; i < numVertex; i++)
        marks[i] = false;
}
// Marca o vértice como "percorrido"
void Graph::markVertex(Vertex vertex){
    int index = getIndex(vertex);
    marks[index] = true;
}
// Retorna status de "percorrido" dos vértice
bool Graph::isMarked(Vertex vertex){
    return(marks[getIndex(vertex)]);
}

// Imprimindo a Matriz de Adjacências
void Graph::printMatrix(){
    for(int row = 0; row < numVertex; row++){
        cout << vertexes[row].getNome() << ":\t|";
        for(int col = 0; col < numVertex; col++)
            cout << " " << edges[row][col] << " |";
        cout << endl;
    }
}

