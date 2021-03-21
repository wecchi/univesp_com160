# COM160 - Estrutura de Dados

Estruturas básicas para representação de dados: pilhas, filas e listas ligadas, árvores, grafos, tabelas de hash e
suas generalizações, implementações. Algoritmos para construção, consulta e manipulação de tais estruturas.
Desenvolvimento, implementação e testes de programas usando tais estruturas em aplicações específicas. Page-Rank.. 

## Exercícios práticos:

Relacionei alguns exercícios realizados no 1º bimestre/2021 durante as aulas da disciplina COM160 do Curso de Bacharel de Ciência de Dados da Univesp. Abaixo segue uma breve descrição do problema de negócios e da solução em C++ (o link direciona para o código):

<dl>
<dt>Conceitos gerais da linguagem C++</dt>
<dd>

1. [Hello World](Sem1/helloworld.cpp): estrutura básica de um progrma em C++, formas de compilar com g++ e impressão no console.
2. [Operações aritméticas](Sem1/operacoes_matematicas.cpp): dado entrada de dois números pelo usuário, realizar operações elementares de soma, subtração, multiplicação e divisão.
3. [Condicionais](Sem1/condicionais.cpp): dado entrada de dois números pelo usuário, compará-los e imprimir no console resultados de operador relacional.
4. [Estrutura WHILE](Sem1/repeticao_while.cpp): contar a quantidade de números menores que cinco informados pelo usuário no console. Apresentação da sintaxe para utilização de estrutura de repetição com teste na cabeça, isto é, no início do laço.
5. [Estrutua FOR](Sem1/repeticao_for.cpp): calcular a soma de uma série. Sintaxe básica para utilização de estrutura de repetição por faixa de valor.
6. [Estrutura DO_WHILE](Sem1/repeticao_do_while.cpp): calcular a média de números digitadoe pelo usuário. Apresentação da sintaxe para utilização de estrutura de repetição com teste na cauda, isto é, no final do laço.
7. [Declaração de função](Sem1/declaracao_funcao.cpp): dado entrada de dois números pelo usuário, realizar operações elementares de soma, subtração, multiplicação e divisão. Apresentação da sintaxe para declaração e uso de função em um programa.
8. [Passagem de parâmetro por valor](Sem1/parametro_valor.cpp): exemplo de como uma função recebe parâmetros por valor.
9. [Passagem de parâmetro por referência](Sem1/parametro_referencia.cpp): exemplo de como uma função recebe parâmetros por referência.
10. [Ponteiros](Sem1/ponteiros.cpp): exemplos de declaração, inicialização e atribuição de valor a ponteiros de memória de maneira estática (STACK)  e de maneira dinâmica (HEAP).
11. [Declaração e inicialização de vetor](Sem1/vetores_bas.cpp): como deve ser feita a declaração e inicialização de vetor de inteiros.
12. [Vetor estático](Sem1/vetores_cte.cpp): implementando uma constante para definir o tamanho do vetor na declaração e inicialização de vetor de inteiros.
13. [Passagem de ponteiros](Sem1/passagem_ponteiro.cpp): verificação de três diferentes formas de tratar ponteiros por um método. Imprimindo seus valores antes e depois para fim de comparação.
14. [Métodos para manipulação de vetor](Sem1/modifica_vetor.cpp): dado dois vetores de inteiros, crie métodos que alterem seus valores e um outro método que manipule os dados e some os elementos do vetor mantendo a imutabilidade do vetor original.
</dd>

<dt>Exercícios de fixação de '<a href= "https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp0_Introduction.html" target="_blank">C++ Programming Tutorial</a>'</dt>
<dd>

15. [Impressão de padrões](Sem1/PrintPatternX.cpp): imprimindo padrões usando o comando _cout_.
16. [Operações matemáticas básicas com números inteiros](Sem1/Add2Numbers.cpp): dado entrada de dois números pelo usuário, realizar operações elementares de soma, subtração, multiplicação e divisão. Apresentação da sintaxe para declaração em uma única linha. 
17. [Soma e multiplicação de cinco inteiros](Sem1/FiveIntegerArithmetic.cpp): dado entrada de cinco números pelo usuário, computar a soma e o produto desses números.
18. [Área e circunferência de um círculo](Sem1/CircleComputation.cpp): com base num raio de um círculo, calcular sua circunferência e área.
19. [Área e perímetro de um retângulo](Sem1/RetanguleComputation.cpp): conforme informações de comprimento e largura de um retângulo, calcular perímetro e área.
20. [Volume e superfície de um cilindro](Sem1/CylinderComputation.cpp): dado um cilindro sólido de raio _r_ e altura _h_, calcular a área da superfície e seu volume.
21. [Soma de números pares e ímpares](Sem1/SumOddEven.cpp): com base numa série aritmética unitária de tamanho _n_ informado pelo usuário, calcular as somas dos valores pares, ímpares e a diferença entre eles. 
22. [Soma de números múltiplos por 13, 15 e 17](Sem1/SumDivisibleBy13_15_17.cpp): dada uma série aritimética unitária de tamanho _n_, informado pelo usuário, calcular a soma dos termos que sejam divisíveis por 13 ou 15 ou 17, mas que não sejam por 30.
23. [Anos bissextos](Sem1/ShowLeapYears.cpp): calcular e apresentar TODOS os anos [bissextos](https://pt.wikipedia.org/wiki/Ano_bissexto) comprendido entre dois anos informados pelo usuário.
24. [Conversor de temperaturas](Sem1/ConvertTemperature.cpp): conversor de temperaturas fahrenheit-celsius e vice-versa.
25. [Cálculo de médias](Sem1/TestCastingAverage.cpp): apresentação do comportamento da linguagem C++ ao dividir números com formatos inteiro. Uso de _cast_.
26. [Série harmônica](Sem1/HarmonicSeriesSum.cpp): calcular a soma de _n_ termos de uma série harmônica informado pelo usuário (1 + 1/2 + 1/3 + 1/4 + .... + 1/n).
27. [Série geométrica](Sem1/GeometricSeriesSum.cpp): calcular a soma de _n_ termos de uma série geométrica informado pelo usuário (1 + 1/2 + 1/4 + 1/8 + .... + 1/n).
</dd>

<dt>As visões das estruturas de dados (**lógica** - classes criadas em arquivos _.h_ , **implementação** - arquivos _.cpp_ com _include_ do arquivo _.h_ e **aplicação**)</dt>
<dd>

28. [Classe time](Sem2/time_main.cpp): criar uma classe que represente a estrutra de tempo em horas, minutos e segundos.
29. [Pilha implementada com vetor](Sem2/stack_test.cpp): criar uma estrurura de dados que receba um texto e a inverta, usando o conceito de pilha.
30. [Fila implementada com vetor](Sem2/queue_test.cpp): criar uma estrurura de dados que receba um texto usando o conceito de fila.
</dd>

<dt>Organização dos dados na memória (contíguo ou disperso):<br/>
Definir critérios para decidir qual forma de organização de dados na memória é mais adequada para cada situação;<br/>
Compreender o encadeamento das estruturas lineares na memória por meio de ponteiros;<br/>
Entender a diferença na implementação de pilhas e filas com vetores e com listas encadeadas.</dt>
<dd>

31. [Pilha com lista encadeada](Sem3/stack_test.cpp): criar uma estrutura de dados com para representar uma **pilha** de caracteres digitados pelo usuário na forma de lista encadeada - ponteiro de memória.
32. [Verifica sintaxe de literais](Sem3/checkSintaxe.cpp): Verificação de strings bem formadas (aninhamento de parênteses, chaves e colchetes) o algoritmo empilha todos os caracteres de abertura enquanto estivermos lendo a string da esquerda para a direita. Se encontrarmos um caractere de fechamento na leitura da string, então desempilhamos o elemento do topo e verifica se o elemento de fechamento "casa" com o que está no topo. A string estará bem formada se, ao final do processo, a pilha estiver vazia.
33. [Fila com lista encadeada](Sem3/queue_test.cpp): criar uma estrutura de dados com para representar uma **fila** de caracteres digitados pelo usuário na forma de lista encadeada - ponteiro de memória.
34. [Verifica palíndrome](Sem3/palindrome.cpp): implementação de fila e pilha para checar se um texto digitado pelo usuário é uma palíndrome.

</dd>

<dt>Tabelas Hash: permitem buscas em tempo constante, satisfeitas algumas restrições. Essa estrutura de dados pode ter vários nomes como: dicionários, mapas, arrays associativos, e assim por diante.<br />
A função de espalhamento recebe uma chave de busca e retorna um endereço de memória onde um registro com aquela chave pode ser encontrado.</dt>
<dd>

35. [Lista de alunos RAs e Nomes com vetor](Sem4/hash_basic.cpp): implementação de uma tabela Hash para armazenamento e busca de dados de aluno - problema de colisão
36. [Lista de alunos RAs e Nomes com teste linear](Sem4/hash_linear.cpp): O teste linear agrupa os elementos em posições contíguas. As pesquisas podem se tornar lentas.

</dd>
</dl>