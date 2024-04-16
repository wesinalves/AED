#include <iostream>
#include <list>

// Nesse exemplo, usaremos a Lista nativa do C++, dada pela STL list, uma vez que, por padrao
// ela implementa uma Lista duplamente encadeada. Eh recomendavel que o aluno repita o mesmo exercicio
// implementando Listas duplamente encadeadas com ponteiros

using namespace std;

class Lista{
	public:
		list<int> lista;
		Lista(){};
		Lista(int Elemento){
			this->lista.push_back(Elemento);
		}
		void inserirElementos();
		void inserirElementoAoFinal(int &Elemento);
		void inserirElementoNaPosicao(int Elemento, int Posicao);
		void removerElementos();
		void buscarElementos(int Elemento);
		int primeiraOcorrencia (int Elemento);
		void apresentarLista();
		void removerElemento(int posicao);
};

int main(){
	setlocale(LC_ALL,"");
	int n;
	Lista Lst;
	while(1){
	do{
	cout << "Escolha uma opcao:" << endl;
	cout << "1. Inserir Elemento na Lista" << endl;
	cout << "2. Remover um Elemento da Lista" << endl;
	cout << "3. Buscar um Elemento na Lista " << endl;
	cout << "4. Exibir a Lista" << endl;
	cin >> n;
	}
	while(n<0 || n>4);
	int Elemento;
	int posicao;
	switch(n){
		case 1:
			Lst.inserirElementos();
			break;
		case 2:
			Lst.removerElementos();
			break;
		case 3:
			cout << "Entre com o elemento a ser encontrado" << endl;
			cin >> Elemento;
			Lst.buscarElementos(Elemento);
			break;
		default:
			Lst.apresentarLista();
			break;
	}
system("pause");
system("cls");
}
return 0;
}

void Lista::inserirElementos(){
	int n;
		do{
		cout << "Como voce deseja inserir o elemento?" << endl;
		cout << "1. Lista final da Lista" << endl;
		cout << "2. Em uma posicao conhecida" << endl;
		cin >> n;
		}while(n<0 || n>2);
		
	int elemento, posicao;
		
	switch(n){
		case 1:
			cout << "Entre com o Elemento que voce deseja inserir" << endl;
			cin >> elemento;
			inserirElementoAoFinal(elemento);
			break;
		case 2:
			cout << "Entre com o Elemento que voce deseja inserir" << endl;
			cin >> elemento;
			cout << "Entre com a posicao onde voce deseja que o elemento seja inserido" << endl;
			cin >> posicao;
			inserirElementoNaPosicao(elemento, posicao);
			break;
	}
} 

void Lista::inserirElementoAoFinal(int &Elemento){
	lista.push_back(Elemento);
}

void Lista::inserirElementoNaPosicao(int Elemento, int Posicao){
	list<int>::iterator it;
	it = lista.begin();
	for (int i=0; i<Posicao-1; i++){
		it++;
	}
	//extende a lista inserindo um novo elemento em uma determinada posicao.
	lista.emplace(it,Elemento); 
}

void Lista::buscarElementos(int Elemento){
	list<int>::iterator it;
	int i=1;
	for (it = lista.begin(); it!=lista.end(); it++){
		if (*it == Elemento){ 
			cout << "O elemento esta presente na " << i << "a posicao" << endl; 
			}
		i++;
	}
}

void Lista::apresentarLista(){
	list<int>::iterator it;
	for (it = lista.begin(); it!=lista.end(); it++){
		cout << *it << "\t";
	}
	cout << endl;
}

void Lista::removerElementos(){
		int n;
		do{
		cout << "Como voce deseja remover o elemento?" << endl;
		cout << "1. Por valor (primeira ocorrencia do valor)" << endl;
		cout << "2. Pela Posicao" << endl;
		cin >> n;
		}while(n<0 || n>2);
		
	int valor, posicao;
		
	switch(n){
		case 1:
			cout << "Entre com o Valor do Elemento que voce deseja remover" << endl;
			cin >> valor;
			if (primeiraOcorrencia(valor)>=0){
				removerElemento(primeiraOcorrencia(valor));
			}
			else{
				cout << "Erro! Elemento nao encontrado na lista" << endl;
			}
			break;
		case 2:
			cout << "Entre com a posicao da lista a ser excluida" << endl;
			cin >> posicao;
			removerElemento(posicao-1);
			break;
	}
	
}

int Lista::primeiraOcorrencia (int Elemento){
	list<int>::iterator it;
	int i=0;
	for (it = lista.begin(); it!=lista.end(); it++){
		if (*it == Elemento){ 
			return i;
			}
		i++;
	}
	return -1;
}


void Lista::removerElemento(int posicao){
	list<int>::iterator it;
	it = lista.begin();
	for (int i=0; i<posicao; i++){
		it++;
	}
	lista.erase (it);
}

 
