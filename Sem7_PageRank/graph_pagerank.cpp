 /* 
  * Videoaula 21 -  03:20
  * Quem invoca o getPageRanks é responsável por saver o tamanho do vetor (número de vértives)
  * A implementação do tamanho cabe ao chamador
  */
#include <iostream>
#include "graph.h"
#include "queue.h"

using namespace std;
int main() {
  // Criando o objeto graph
  Graph graph;
  // Criando os vértices (ou nós)
  Vertex a = Vertex("A"); Vertex b = Vertex("B");
  Vertex c = Vertex("C"); Vertex d = Vertex("D");

  // Adicionando ao Grafo os vértices (ou nós)
  graph.addVertex(a); graph.addVertex(b);
  graph.addVertex(c); graph.addVertex(d);
  // Adicionando ao Grafo as arestas (ou arcos)
  graph.addEdge(a, c, 1); graph.addEdge(a, b, 1);  
  graph.addEdge(b, d, 1); 
  graph.addEdge(c, a, 1); graph.addEdge(c, b, 1); graph.addEdge(c, d, 1);    
  graph.addEdge(d, c, 1);  
  
  // Criando a variável de saída para o PageRank
  float* pageRanks = new float[4];
  char nodes[4] = {'A', 'B', 'C', 'D'};
  // Invocando o método PageRanks para obtenção dos valores dos vértices
  graph.getPageRanks(pageRanks);

  // Exibindo o resultado ao usuário
  cout << "\n---- Matriz de adjacencias ----" << endl;
  graph.printMatrix();
  cout << "\n---- PageRank dos vertices ----" << endl;
  for (int i = 0; i < 4; i++){
      cout << nodes[i] << ":" <<pageRanks[i];
      if (i < 3) cout << " ; ";
      else cout << endl;
  }

}
