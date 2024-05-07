#include <iostream>
#include <stack> // inclui biblioteca para a pilha
#include <string>

using namespace std;

int main(){
	
	stack<string> cartas;
	
	cartas.push("Rei de Copas");
	cartas.push("Coringa");
	cartas.push("Rei de Espadas");
	cartas.push("7 de Copas");
	
	// mostra o tamanho da pilha pois � alocavel
	cout << "tamanho da pilha: " << cartas.size() << endl; 
	
	//retorna o termo que entrou por ultimo
	cout << "carta do topo: " << cartas.top() << "\n\n"; 
	
	///*
	// retira a ultima carta do baralho, pois como
	// foi a ultima a entrar vai ser a primeira a sair
	cartas.pop(); 
	//cartas.pop();
	
	cout << "\ntamanho da pilha: " << cartas.size() << endl; 
	
	cout << "carta do topo: " << cartas.top() << endl; 
	//*/
	
	
	/*
	while(!cartas.empty()){
	cartas.pop();			// metodo para zerar a pilha
	}
	
	
	cout << "\ntamanho da pilha: " << cartas.size() << endl; 
	
	cout << "carta do topo: " << cartas.top() << endl; 
	*/
	
	/*
	while(!cartas.empty()){
	cout << cartas.top() << endl;
	cartas.pop();				// metodo para zerar a pilha
	}*/
	
	
	return 0;	
}
