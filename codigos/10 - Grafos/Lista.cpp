#include <iostream>
#define max 5
using namespace std;

class Grafo{
	
    public:	
    
 // Cada vértice recebe o valor de seu índice //
	int vertice[5];
	
	int aresta[max][max];
	int auxv[max];
	
	
	void grau_vertice(int aresta[][max], int auxv[]){  // Este método verifica o grau de todos os vértices  // 
		
		for(int i = 0; i<max; i++){
		
			for(int j = 0; j<max; j++){
			
				if(aresta[i][j] == 1 || aresta[j][i] == 1){
					
					auxv[i]++;
				}
			}
		}
		
		for(int l = 0; l<max; l++){
			
			if(auxv[l] != 0){
				
				cout << "O vertice " << l << " tem grau " << auxv[l] << endl;
			}
		}
		
	}

	void amigos(int aresta[][max]){  // Método para encontrar vértices amigos //
	
		for(int m = 0; m<max; m++){
			
			cout << " Amigos de " << m << " :" << endl;
			
			for(int n = 0; n<max; n++){
				
				if(aresta[m][n] != 0 || aresta[n][m] != 0){
					
					cout << " " << n << endl;
				}
			}
		}
	}
};

int main(){
	
	Grafo grafo;					
	
	// Gerando um grafo de 5 vértices a partir de uma matriz que possui '1' nas posições em que há aresta entre os elementos representados //
		
	grafo.aresta[0][1] = 1;
	grafo.aresta[1][2] = 1;
	grafo.aresta[2][3] = 1;
	grafo.aresta[3][0] = 1;
	grafo.aresta[3][1] = 1;
	grafo.aresta[4][2] = 1;
	grafo.aresta[4][3] = 1;

	
	// Agora os complementares //
	
	for (int a = 0; a<max; a++){
		
		for (int b = 0; b<max; b++){
			
			if(grafo.aresta[a][b] != 1){
				
				grafo.aresta[a][b] = 0;
			}
		}
	}
	
	//
	
	grafo.vertice[0] = 0;
	grafo.vertice[1] = 1;
 	grafo.vertice[2] = 2;
	grafo.vertice[3] = 3;
 	grafo.vertice[4] = 4;
	
	// Verifica o grau de cada vértice //
	
	grafo.auxv[0] = 0;
	grafo.auxv[1] = 0;
	grafo.auxv[2] = 0;
	grafo.auxv[3] = 0;
	grafo.auxv[4] = 0;

	
	grafo.grau_vertice(grafo.aresta, grafo.auxv);

	// Verifica a vizinhança e encontra os vértices "amigos" //
	
	
	grafo.amigos(grafo.aresta);

	
	return 0;
}
