#include <iostream>
using namespace std;

class sentinela{

	public:
		
		int inserir(int n, int a[]){
			
			int i;
			
			cout << "Escreva os numeros separados por enter" << endl;
			
			for (i=0; i<n; i++){
				
				cout << "Elemento na posicao " << i << endl;
				cin >> a[i];
					
			}
			
			return 0;
			
		}
		
		void mostrar(int n, int a[]){
			
			int i;
			
			for (i=0; i<n; i++){
				
				cout << a[i] << endl; 
				
			}
			
		}
		
		int busca(int x, int n, int a[]){
			
			int i=0;
			
			a[n] = x;
			
			while(a[i] != x){
			
				i++;
				
			}
			
			if (i==n){
						
				cout << "O elemneto nao se encontra no vetor" << endl;	
					
			}
			
			else
			
				cout << "O elemento se enocntra na posicao " << i << endl;
			
			return (i==n) ? -1 : i;
			//Finaliza a execucao do metodo e retorna o controle para
			//o metodo de chamada, no ponto imediatamente apos a chamada.
			
		}
	
};

int main(){
	
	sentinela sent;
	int j, r; 
	const int l=10;
	int v[l+1];
	

	while (4){
		
		cout << "1) Inserir elemento no array;" << endl;
		cout <<	"2) Apresentar array;" << endl;
		cout <<	"3) Informar elemento a ser buscado;" << endl;
		cout <<	"4) Sair do programa." << endl;
		cin >> j;
		
		switch (j){
		
			case 1:{
				
				sent.inserir(l,v);
			
				break;
			}
		
			case 2:{
			
				sent.mostrar(l,v);
			
				break;
			}
			
			case 3:{
			
				cout << "Digite o elemento a ser procurado" << endl;
				cin >> r;
			
				sent.busca(r, l,v);
			
				break;
			}
			
			case 4:{
				
				exit(4);
				
				break;
			}
			
		}
	}
	
	return 0;
}
