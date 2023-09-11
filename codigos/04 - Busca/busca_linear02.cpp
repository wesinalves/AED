#include <iostream>
using namespace std;


int buscalinear(int vector[], int tamanho, int key){	
	int i;
	for (i=0;i<tamanho;i++){
		if (vector[i]==key){
			return i;
		}
	}
	return -1;
}
	
int main() {
	
	int aux, v;
	int valores[5];
	
	cout<<"insira os valores separados por enter"<<endl;
	
	for(aux=0; aux<5; aux++){	
		cin>>v;	
		valores[aux]=v;	
	}
	
	int tamanho = 5;	
	int procura,res;
	
	cout << "Qual valor a ser procurado?" << endl;
	
	cin >> procura;
	
	res=buscalinear(valores,tamanho,procura);
	
	if (res==-1)
		cout << "O valor procurado nao foi encontrado.";
	else
		cout << "O valor procurado encontra-se na posicao " << res;
	return 0;

}
