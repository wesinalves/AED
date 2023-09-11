#include <iostream>
using namespace std;

void preencher(int v[]){
	v[0] = 13;
	v[1] = 56;
	v[2] = 76;
	v[3] = 19;
	v[4] = 23;
	v[5] = 34;
}

int main(){
	int v[6];
	int n, i;	
	bool achou;
	
	preencher(v);	//funcao para preencher os valores
	achou = false;	//setar a variavel "achou" como false
	
	cout << "Insira o numero que deseja procurar:\n";
	cin >> n;	//insira o numero que deseja procurar
	
	for(i=0 ; i<6 ; i++){		
		if(v[i] == n){
			achou = true; //caso ache o numero digitado pelo
						  //usuario a variavel achou muda para "true"
		}
	}
	
	if (achou==true){
		//condicao para caso o numero digitado for encontrado
		cout << "\nO numero "<< n <<" foi encontrado";	
	}else{
		//condicao para caso o numero digitado Nao for encontrado
		cout <<"\n" << n << " nao foi encontrado\n";	
	}
	
	
	return 0;
}
