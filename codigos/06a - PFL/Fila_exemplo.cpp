#include <iostream>
#include <queue> //biblioteca para a fila
#include <string>

using namespace std;

int main(){
	
	queue<string> cartas;
	
	cartas.push("Rei de Copas");
	cartas.push("Coringa");
	cartas.push("Rei de Espadas");
	cartas.push("7 de Copas");
	
	//a diferença é que em fila ao inves de "top"
	//se usa front ou back para se referir ao conjunto
	cout << "carta do topo: " << cartas.front() << endl; 
	cout << "carta do fundo: " << cartas.back() << "\n\n";
	
	
	//se eu queiser mostrar todos os termos:	
	while(!cartas.empty()){
		cout << cartas.front() << endl; 
		cartas.pop();
	}
	
	
	return 0;
	
}

