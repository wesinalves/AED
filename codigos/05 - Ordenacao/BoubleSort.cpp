#include <iostream>

using namespace std;

void iniciar (int vetor[]){
	vetor[0] = 6;
	vetor[1] = 2;		//inicializar o vetor
	vetor[2] = 3;
	vetor[3] = 5;
	vetor[4] = 1;
	vetor[5] = 4;
	
	
}

int main(){
	int vetor[6];
	int i, aux, j;
	bool continua, troca;
	
	iniciar (vetor);

	continua = 1;		//variável que mantem a o lopp rodando até que o vetor seja organizado

	while(continua == true){

		troca = false;
		
		for(i=0 ; i<5 ; i++){
			
			for (j=0 ; j<6 ; j++){
						cout << vetor[j];
						if(vetor[j] == vetor[i]){
							cout << "<--";
						}
						if(vetor[j] == vetor[i+1]){
							cout << "<--";
						}
						cout << endl;
					}
				
				system("pause");
				system("cls");
			
			if (vetor[i] > vetor[i+1]){		//se o termo i for maior do que o termo i+1, eles serão trocados
				
				aux = vetor[i+1];
				vetor[i+1] = vetor[i];
				vetor[i] = aux;
				troca = true;
				
					for (j=0 ; j<6 ; j++){
						cout << vetor[j];
						if(vetor[j] == vetor[i]){
							cout << "<--";
						}
						if(vetor[j] == vetor[i+1]){
							cout << "<--";
						}
						cout << endl;
					}
				
				system("pause");
				system("cls");
			}
		}
		
		if(troca == false){
			continua = false;		//se não houver nenhuma trca durante a varredura, o programa sai do loop while
		}
		
	}
	
	for (i=0 ; i<6 ; i++){
		cout << vetor[i] << "\n";
	}
	
	return 0;
}
