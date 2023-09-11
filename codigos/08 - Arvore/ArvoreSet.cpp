#include <iostream>
#include <set>

using namespace std;

/* Na STL, a implementa��o do container set � uma �rvore bin�ria de busca, sendo auto-balanceada de acordo com os crit�rios
de balanceamento das �rvores rubro-negras
� importante ressaltar que, em containers do tipo set, � poss�vel e remover elementos, bem como encontrar elementos
de forma muito r�pida, mas n�o � poss�vel modificar o valor de elementos existentes, assim como em �rvores bin�rias 
*/

int main(){
	setlocale(LC_ALL,"");
	int n, auxiliar;
	set<int> arvoreBinaria;
	string desejaContinuar;
	while(1){
		system("cls");
	do{
		cout << "Escolha uma op��o: " << endl;
		cout << "1. Inserir elemento na �rvore" << endl;
		cout << "2. Remover um elemento da �rvore" << endl;
		cout << "3. Procurar elemento na �rvore" << endl;
		cout << "4. Exibir �rvore ordenada" << endl;
		cout << "5. Sair do programa" << endl;
		cin >> n;		
	}while(n<0 || n>5);
	
	switch(n){
		case 1:
			cout << "Entre com o elemento que voc� deseja inserir" << endl;
			cin >> auxiliar;
			arvoreBinaria.insert(auxiliar);
			break;
		case 2:
			cout << "Entre com o elemento que voc� deseja remover" << endl;
			cin >> auxiliar;
			arvoreBinaria.erase(auxiliar);
			break;;
		case 3:
			cout << "Entre com o elemento que voc� deseja verificar se est� na �rvore" << endl;
			cin >> auxiliar;
			if (arvoreBinaria.find(auxiliar)!=arvoreBinaria.end()){
				cout << "O elemento " << auxiliar << " est� presente na �rvore" << endl;
			}
			else{
				cout << "O elemento " << auxiliar << " n�o est� presente na �rvore" << endl;
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
