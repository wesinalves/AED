#include <iostream>
using namespace std;

void preencher(int v[]){
	v[0] = 13;
	v[1] = 56;
	v[2] = 76;
	v[3] = 19;
	v[4] = 23;

}

int main(){
	int v[6];
	int n, i, sentinela;	
	bool achou;
	
	preencher(v);	//funcao para preencher os valores
	achou = false;	// setar a variavel "achou" como false
	
	cout << "Insira o numero que deseja procurar:\n";
	cin >> n;	//insira o numero que deseja procurar
	
	sentinela = n;
	v[5] = sentinela; //sentinela
	
	for(i=0 ; v[i] != sentinela ; i++){	//a busca continuara ate o v[i] ter o valor do sentinela	
	}
	
	if((i != 5) && (v[i] == n)){
		achou = true; //caso ache o numero digitado pelo usuario
					  //a variavel achou muda para "true"
	}
	
	if(achou==true){
		//condicao para caso o numero digitado for encontrado
		cout << "\no numero "<< n <<" foi encontrado\n\n";	
	}
	if(achou==false){
		//condicao para caso o numero digitado nao for encontrado
		cout <<"\no numero " << n << " nao foi encontrado\n\n";	
	}	
	
	return 0;
}
