// Grafos - BFS (busca em largura)

#include <iostream>
#include <list>
#include <queue> // fila para usar na BFS

using namespace std;

class Grafo
{
	int V; // n�mero de v�rtices
	list<int> *adj; // ponteiro para um array contendo as listas de adjac�ncias
	// para cada v�rtice h� uma lista com os seus vizinhos

public:
	Grafo(int V); // construtor com o num de v�rtices
	void adicionarAresta(int v1, int v2); // adiciona uma aresta no grafo
										// saindo de v1 e chegando a v2

	// faz uma BFS a partir de um v�rtice
	void bfs(int v);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o n�mero de v�rtices
	adj = new list<int>[V]; // cria as listas
	//cada v�rtice tem uma lista com os seus vizinhos
	//se temos v v�rtices teremos v listas
}

void Grafo::adicionarAresta(int v1, int v2)
{
	// adiciona v�rtice v2 � lista de v�rtices adjacentes de v1
	adj[v1].push_back(v2);
}

void Grafo::bfs(int v)
/*no_corrente = raiz
visitados[no_corrente] = true
enquanto verdade;
	percorre todos os vizinhos
		se vizinho N�O tiver sido visitado
		marcar o vizinho como visitado
		insere o vizinho na fila
		se a fila n�o estiver vazia 
			v = fila.frente()
			fila.remove()
		senao
			sai do loop
*/
{
	queue<int> fila;
	bool visitados[V]; // vetor de visitados

	// marca todos como n�o visitados
	for(int i = 0; i < V; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << v << " ...\n";
	visitados[v] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it; //para percorrer todos os elementos da lista
		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])//*it para acessar o conte�do
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; // marca como visitado
				fila.push(*it); // insere na fila
			}
		}

		// verifica se a fila N�O est� vazia
		if(!fila.empty())
		{
			v = fila.front(); // obt�m o primeiro elemento
			fila.pop(); // remove da fila
		}
		else
			break;
	}
}

int main()
{
	system("color F0");
	int V = 8;

	Grafo grafo(V);

	// adicionando as arestas
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(1, 4);
	grafo.adicionarAresta(2, 5);
	grafo.adicionarAresta(2, 6);
	grafo.adicionarAresta(6, 7);

	grafo.bfs(2);

	return 0;
}

