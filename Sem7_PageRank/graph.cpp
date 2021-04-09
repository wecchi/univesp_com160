 /* 
  * Videoaula 21 -  05:46
  * Implementação do método getPageRanks()
  * na classe de implementação graph.cpp
  */

#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph(int max, int null_edge) {
  NULL_EDGE   = null_edge; 
  maxVertices = max;  
  numVertices = 0;
  vertices = new Vertex[maxVertices];
  marks = new bool[maxVertices];
  edges = new int* [maxVertices];
  
  // Criando matriz de adjacências
  for (int row = 0; row < maxVertices; row++)
    edges[row] = new int[maxVertices];  
  // Populando matriz de adjacências com valor nulo     
  for (int row = 0; row < maxVertices; row++)
    for (int col = 0; col < maxVertices; col++)
      edges[row][col] = NULL_EDGE;
}

Graph::~Graph() {
  delete [] vertices;
  delete [] marks;
  for (int row = 0; row < maxVertices; row++){
    delete [] edges[row];
  }
  delete [] edges;
}

int Graph::getIndex(Vertex vertex) {
  int index = 0;
  while (!(vertex.getNome() == vertices[index].getNome())){
    index++;
  }
  return index;
}

void Graph::addVertex(Vertex vertex){
  vertices[numVertices] = vertex;
  numVertices++;
}
void Graph::addEdge(Vertex fromVertex,
		    Vertex toVertex,
		    int weight){
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);

  edges[row][col] = weight;
  // Remover se grafo direcionado.
  // edges[col][row] = weight; 
}

int Graph::getWeight(Vertex fromVertex,
		     Vertex toVertex){
  int row = getIndex(fromVertex);
  int col = getIndex(toVertex);
  return edges[row][col];
}

void Graph::getAdjacents(Vertex vertex,
			 Queue &adjVertices){
  int fromIndex;
  int toIndex;
  fromIndex = getIndex(vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      // Uma cópia do elemento é adicionada no array.
      adjVertices.enqueue(vertices[toIndex]);
}

void Graph::clearMarks(){
  for (int i = 0; i < numVertices; i++)
    marks[i] = false;    
}
void Graph::markVertex(Vertex vertex){
  int index = getIndex(vertex);
  marks[index] = true;
}
bool Graph::isMarked(Vertex vertex){
  int index = getIndex(vertex);
  return marks[index];  
}

// Imprimindo a Matriz de Adjacências
void Graph::printMatrix(){
    for(int row = 0; row < numVertices; row++){
        cout << vertices[row].getNome() << ":\t|";
        for(int col = 0; col < numVertices; col++)
            cout << " " << edges[row][col] << " |";
        cout << endl;
    }
}

void Graph::getPageRanks(float* pageRanks){
  // Computando graus de saída outputDegree[i], esse número será usado para dividir a pontuação do nó para seus adjacentes
  int* outputDegree = new int[numVertices];
  for (int i = 0; i < numVertices; i++) {
    outputDegree[i] = 0;
    for (int j = 0; j < numVertices; j++) {
      if (edges[i][j] != NULL_EDGE) {
	      outputDegree[i] += 1;
      }
    }
  }
  
  // Computando pageRanks.
  float* pr_previous = new float[numVertices];  // valores na iteração anterior
  float* pr_actual   = new float[numVertices];  // valores na iteração atual
  
  // Inicializando todos os pageRanks com mesmo peso, isso é 1 dividido pelo número de vértices (ou nós)
  for (int i = 0; i < numVertices; i++) {
    pr_previous[i] = 1.0/numVertices;
  }

  // definindo o fator de amortecimento - recomendado pela litetartura
  float d = .85;
  for (int numIter = 0; numIter < 100; numIter++){        // quantidade de iterações para convergência dos valores PageRanks
    // Passo Iterativo
    for (int col = 0; col < numVertices; col++){
      pr_actual[col] = 0;
      // Obter a soma dos PageRanks recebidos no nó "j"
      for (int row = 0; row < numVertices; row++){
        if (edges[row][col] != NULL_EDGE){                      // só vamos computar para arestas existentes
          pr_actual[col] += pr_previous[row]/outputDegree[row]; // outputDegree[row] é o número de predecessores de [row]
        }
      }
      // atualiza o PageRank com a fórmula considerando fator de amortecimento
      pr_actual[col] = (1-d)/numVertices + d*pr_actual[col];   
    }
    // Terminada a iteração, transfere todos os valores "atuais" para "anteriores" a fim de uma noca iteração
    for (int i = 0; i< numVertices; i++){
      pr_previous[i] = pr_actual[i];
    }
  }

  // Retornando os valores para quem chamou a função
  for (int i = 0; i< numVertices; i++){
    pageRanks[i] = pr_actual[i];
  }

  // Desalocando a memória que foi usada para o cálculo
  delete [] pr_previous;
  delete [] pr_actual;
  delete [] outputDegree;
  
}
