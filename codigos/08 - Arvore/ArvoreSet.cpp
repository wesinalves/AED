#include <iostream>
#include <set>

using namespace std;

/* Na STL, a implementação do container set é uma árvore binária de busca, sendo auto-balanceada de acordo com os critérios
de balanceamento das árvores rubro-negras
É importante ressaltar que, em containers do tipo set, é possível e remover elementos, bem como encontrar elementos
de forma muito rápida, mas não é possível modificar o valor de elementos existentes, assim como em árvores binárias 
*/

int main(){
	setlocale(LC_ALL,"");
	int n, auxiliar;
	set<int> arvoreBinaria;
	string desejaContinuar;
	while(1){
		system("cls");
	do{
		cout << "Escolha uma opção: " << endl;
		cout << "1. Inserir elemento na árvore" << endl;
		cout << "2. Remover um elemento da árvore" << endl;
		cout << "3. Procurar elemento na árvore" << endl;
		cout << "4. Exibir árvore ordenada" << endl;
		cout << "5. Sair do programa" << endl;
		cin >> n;		
	}while(n<0 || n>5);
	
	switch(n){
		case 1:
			cout << "Entre com o elemento que você deseja inserir" << endl;
			cin >> auxiliar;
			arvoreBinaria.insert(auxiliar);
			break;
		case 2:
			cout << "Entre com o elemento que você deseja remover" << endl;
			cin >> auxiliar;
			arvoreBinaria.erase(auxiliar);
			break;;
		case 3:
			cout << "Entre com o elemento que você deseja verificar se está na árvore" << endl;
			cin >> auxiliar;
			if (arvoreBinaria.find(auxiliar)!=arvoreBinaria.end()){
				cout << "O elemento " << auxiliar << " está presente na árvore" << endl;
			}
			else{
				cout << "O elemento " << auxiliar << " não está presente na árvore" << endl;
			}
			break;
		case 4:
			for(set<int>::iterator it = arvoreBinaria.begin(); it!=arvoreBinaria.end(); it++){
				cout << *it << "\t";
			}
			cout << endl;
			break;
		default: 
			return 0;
	}
	system("pause");
};
	return 0;
	
	
}
