// Grafo - Matriz de adjacência
#include <iostream>
using namespace std;

class Grafo{
	
	public:
	int vertice[5][5]; // Declarada aqui a matriz de adjacência do Grafo
	int v1,v2;
	
	bool tem_ligacao(int v1, int v2){ // Método que retorna true se houver aresta entre os vértices v1 e v2
		if(vertice[v1][v2])
			return true;
		return false;
	}		
	void mostra(){
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				if(tem_ligacao(i,j)){
					cout << "Os vertices " << i << " e " << j << " possuem uma aresta entre eles" << endl;	
				}
			}
		}
	}
	void inicializa(int vertice[][5]){
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				if(vertice[i][j] != 1){
					vertice[i][j] = 0;
				}
			}
		}
	}
};

int main(int argc, char *argv[]){
	
	system("color F0");
	Grafo grafo; // Classe instanciada
	// Declarando elementos da matriz de adjacência
	// Somente os vertices que possuem arestas em comum foram inicializados em '1'
	grafo.vertice[0][2] = 1;
	grafo.vertice[1][2] = 1;  
	grafo.vertice[2][0] = 1;  
	grafo.vertice[2][1] = 1;  
	grafo.vertice[2][3] = 1;  		
	grafo.vertice[2][4] = 1;  		
	grafo.vertice[3][2] = 1;  	
	grafo.vertice[3][4] = 1;  
	grafo.vertice[4][2] = 1;  
	grafo.vertice[4][3] = 1;  
	
	
	grafo.inicializa(grafo.vertice); // Método que inicializa arestas não especificadas em '1'	
	grafo.tem_ligacao(grafo.v1,grafo.v2); // Retorna true se houver aresta, false se não houver.
	grafo.mostra();	
		
	return 0;
}
