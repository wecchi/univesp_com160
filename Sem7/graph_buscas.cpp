 /* 
  * Videoaula 19 -  16:40
  * Em nossa implementação, iremos utilizar as estruturas de dados fila e pilha. 
  * Usaremos os métodos clearMarks, isMarked e markVertex para garantir 
  * que não visitaremos um determinado nó mais de uma vez.
  */

#include <iostream>
#include "graph.h"
#include "stack.h"
#include "queue.h"

using namespace std;

// Busca em PROFUNDIDADE: Como queremos fazer um backtracking sempre que chegarmos a 
// um "beco sem saída", uma pilha será usada para organizarmos os nós.
void depthFirstSearch(Graph& graph, Vertex origem, Vertex destino) {
  Stack  vertexStack; bool found = false; Vertex vertex;
  graph.clearMarks();
  // Origem na pilha
  vertexStack.push(origem);
  
  do {
    // Toda vez que desempilhar alguém, vamos verificar se é o destino
    vertex = vertexStack.pop();
    if (vertex.getNome() == destino.getNome())  {   // Encontrado destino
      cout << "Encontrado: " << vertex.getNome() << ";" << endl;
      found = true;
    } else {                                        // Não encontrado o destino
      if (!graph.isMarked(vertex)) {                // Só faça se o vértice não estiver marcado como visitado
        graph.markVertex(vertex);
        cout << "Visitando: " << vertex.getNome() << endl;
        Queue adjacents;                            // Criar uma fila auxiliar para incluir os nós adjacentes
	      graph.getAdjacents(vertex, adjacents);
      	while (!adjacents.isEmpty()) {
	        Vertex adjacent = adjacents.dequeue();   // Ao desenfileirar um nó adjacente, verifica se está marcado como visitado
          if (!graph.isMarked(  adjacent  )){
            cout << "Empilhando: " << adjacent.getNome() << endl;  // Só vai empilhar os nós adjacentes não marcados como visitados         
            vertexStack.push(adjacent );
          }
      	}
      }
    }
  } while (!vertexStack.isEmpty() && !found);
  if (!found) {
    cout << "Caminho não encontrado." << endl;
  }
}

// Busca em LARGURA: Quemos que os nós sejam visitados em camadas, sem aprofundar muito na busca, 
// uma fila será usada para organizarmos os nós.
void breadthFirstSearch(Graph& graph, Vertex origem, Vertex destino) {
  Queue vertexQueue;  bool found = false; Vertex vertex;
  graph.clearMarks();
  vertexQueue.enqueue(origem);
  do {
    vertex  = vertexQueue.dequeue();    
    if (vertex.getNome() == destino.getNome()) {
      cout << "Encontrado: " << vertex.getNome() << ";" << endl;
      found = true;
    } else {
      if (!graph.isMarked(vertex)) {
	graph.markVertex(vertex);
	cout << "Visitando: " << vertex.getNome() << endl;
	Queue adjacents;
	graph.getAdjacents(vertex, adjacents);
	while (!adjacents.isEmpty()) {
	  Vertex adjacent = adjacents.dequeue();
	  if (!graph.isMarked( adjacent ) ){
	    cout << "Enfileirando: " << adjacent.getNome() << endl;               
	    vertexQueue.enqueue( adjacent ) ;
	  }	    
	}
      }
    }
  } while (!vertexQueue.isEmpty() && !found);
  if (!found)
    cout << "Caminho não encontrado." << endl;
}


int main() {
  Graph graph;

  Vertex a = Vertex("a");
  Vertex b = Vertex("b");
  Vertex c = Vertex("c");
  Vertex d = Vertex("d");
  Vertex e = Vertex("e");
  Vertex f = Vertex("f");
  Vertex g = Vertex("g");
  Vertex h = Vertex("h");
  Vertex i = Vertex("i");
  Vertex j = Vertex("j");

  graph.addVertex(a);
  graph.addVertex(b);
  graph.addVertex(c);
  graph.addVertex(d);
  graph.addVertex(e);
  graph.addVertex(f);
  graph.addVertex(g);
  graph.addVertex(h);
  graph.addVertex(i);
  graph.addVertex(j);
  
  graph.addEdge(a, c, 5);
  graph.addEdge(a, f, 5);
  graph.addEdge(b, a, 1);
  graph.addEdge(b, g, 3);
  graph.addEdge(c, d, 1);
  graph.addEdge(c, i, 5);
  graph.addEdge(d, h, 3);
  graph.addEdge(e, d, 3);
  graph.addEdge(f, e, 1);
  graph.addEdge(g, e, 3);
  graph.addEdge(h, b, 3);
  graph.addEdge(i, g, 1);
  graph.addEdge(i, j, 5);
  graph.addEdge(j, h, 1);
  graph.addEdge(j, f, 5);

  cout << "\n------------------  Matriz de adjacencias  ------------------\n";
  graph.printMatrix(); 

  /******************************************************************
    Obtendo os vértices adjacentes do nó a.
  *******************************************************************/
   cout << "\n------------------  Nos adjacentes da 'a'  ------------------\n";
  Queue adjacents;
  graph.getAdjacents(a, adjacents);
  while (!adjacents.isEmpty()) {
    cout << adjacents.dequeue().getNome() << ", ";
  }
  cout << endl;


  /******************************************************************
    Chamada de DepthFirstSearch
  *******************************************************************/
  cout << "\n------------------  Busca em profundidade (PILHA) a -> b  ------------------\n";
  depthFirstSearch(graph, a, b);

  /******************************************************************
    Chamada de BreadthFirstSearch
  *******************************************************************/
  cout << "\n------------------  Busca em largura (FILA) a -> h  ------------------\n";
  breadthFirstSearch(graph, a, b);
 
  std::cout << "Saindo" << std::endl;
}
