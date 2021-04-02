 /* Videoaula 18 -  17:10
  * Testando a classe de grafos
  */

 #include <iostream>
 #include "graph.h"
 using namespace std;
 Queue q;

 main (){

     Graph graph;
     // Criando os nós ou vértices
     cout << "----------- Creating Vertex --------------\n";
     cout << "A: "; Vertex a = Vertex("A"); cout << &a << endl; graph.addVertex(a);
     cout << "B: "; Vertex b = Vertex("B"); cout << &b << endl; graph.addVertex(b);
     cout << "C: "; Vertex c = Vertex("C"); cout << &c << endl; graph.addVertex(c);
     cout << "D: "; Vertex d = Vertex("D"); cout << &d << endl; graph.addVertex(d);
     cout << "E: "; Vertex e = Vertex("E"); cout << &e << endl; graph.addVertex(e);
     cout << "F: "; Vertex f = Vertex("F"); cout << &f << endl; graph.addVertex(f);

    // Criando as arestas ou arcos
    cout << "\n----------- Constructing Edges --------------\n";
    graph.addEdge(a, a, 1); graph.addEdge(a, b, 2); graph.addEdge(a, c, 1);
    graph.getAdjacents(a, q);
    cout << "[ A ]"; q.print();

    graph.addEdge(b, c, 2); graph.addEdge(b, d, 3);
    q.~Queue(); graph.getAdjacents(b, q);
    cout << "[ B ]"; q.print();

    graph.addEdge(c, a, 2); graph.addEdge(c, d, 5); graph.addEdge(c, e, 4);
    q.~Queue(); graph.getAdjacents(c, q);
    cout << "[ C ]"; q.print();

    graph.addEdge(d, a, 2); graph.addEdge(d, d, 1); graph.addEdge(d, e, 1); graph.addEdge(d, f, 5);
    q.~Queue(); graph.getAdjacents(d, q);
    cout << "[ D ]"; q.print();

    graph.addEdge(e, a, 6); graph.addEdge(e, d, 1); graph.addEdge(e, c, 3);
    q.~Queue(); graph.getAdjacents(e, q);
    cout << "[ E ]"; q.print();

    graph.addEdge(f, b, 9); graph.addEdge(f, e, 5);
    q.~Queue(); graph.getAdjacents(f, q);
    cout << "[ F ]"; q.print();

    // Imprimindo a Matriz de Adjacências
    cout << "\n---------- Adjacency matrix results ------------\n";
    graph.printMatrix();

 }