#include<iostream>
#include<list>

using namespace std;

int main(){
	int i;
	list<int> ex;
	
	//I) declarar Iterator:
	list<int>::iterator it; //declarar o iterator
	
	for(i=1 ; i<11 ; i++){
		ex.push_front(i);  // definir os termos da lista
	}
	
	
	//II) informar por onde o iterator vai começar a contar
	it = ex.begin(); 
	//ou it= ex.end(); se for começar a contar por baixo
	
	//III) definir quantas casas o iterator vai andar
	advance(it,5); 
	//o interator "it" avançará 5 casas
	
	/*
	//IV.I)Insert: qual valor o iterator irá inserir
	
	ex.insert(it,0);
	//o valor a ser inserido na posição 5 será 0
	*/
	
	/*
	//IV.II)Erase: apaga um valor da lista
		ex.erase(it);
	*/
	
	///*
	//IV.III)Merge
		list<int> teste;
		
		teste.push_front(1234);
		teste.push_front(1234);
		teste.push_front(1234);
		teste.push_front(1234);
		cout << "tamanho da lista teste: "  << teste.size() << endl;
		ex.merge(teste);
		
		cout << "tamanho da lista teste: "  << teste.size() << endl;
	//*/
	
		
	for(i=1 ; !ex.empty() ; i++){
		cout << ex.front() << endl;
		ex.pop_front();
	}
	
	

	return 0;
}

