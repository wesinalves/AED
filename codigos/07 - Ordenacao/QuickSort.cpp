#include <iostream>
#include <algorithm>

using namespace std;

void iniciar (int vetor[]){
	vetor[0] = 6;
	vetor[1] = 2;
	vetor[2] = 3;			//inicializa o vetor
	vetor[3] = 5;
	vetor[4] = 1;
	vetor[5] = 4;
	
	
}

int main(){
	int vetor[6];
	int i, j, pivot, parede, troca;
	
	parede = 0;			//inicializa a parede no comeco do vetor
	pivot = 5;			//inicializa o pivot no final do vetor
	
	iniciar (vetor);
	
	while(pivot != 0){
		troca = 0;
		parede = 0;
		
		for(i=0 ; i<5 ; i++){
			
			cout << endl;
			
			if (pivot > i){
			
			for (j=0 ; j<6 ; j++){
						
						if(j == parede){
							cout << "-------  <--parede\n";
						}
				
						cout << vetor[j];
						
						if((j == i) && (j <= pivot) ){
							cout << "  <-- numero que sera comparado com o pivot";
						}
						
						if(j == pivot){
							cout << "  <--pivot";
						}
						cout << endl;
						
					}
				
				system("pause");
			//	system("cls");
			
			}	
			
			if ((vetor[pivot] > vetor[i]) && (pivot > i)){	
				//caso o pivot seja maior do que o elemento q está sendo comparado,
				//esse elemento passa para trás da parede
				
				swap(vetor[i],vetor[parede]);
				parede++; // apos isso a parede anda 1 espaco para frente
				
				cout << endl;
				for (j=0 ; j<6 ; j++){
						
						if(j == parede){
							cout << "-------  <--parede\n";
						}
						
						cout << vetor[j];
						
						if((j == (parede-1)) && (j <= pivot)){
							cout << "  <-- numero foi trocado por ser menor ou igual ao pivot";
						}
						
						if(j == pivot){
							cout << "  <--pivot";
						}
						
						cout << endl;
					}
					
					troca++;
					
				system("pause");
							
			}
			
		}
		
		if(troca >= pivot){
			pivot--;
			parede = 0;		//caso não haja nenhuma troca durante a varredura, o pivot move 1 casa 

		
		cout << "\n\nComo o pivot anterior nao alterou a ordem do vetor e os termos ainda nao foram ordenados, a posicao de pivot mudou\n\n";
		
		for (j=0 ; j<6 ; j++){
						
			if(j == parede){
				cout << "-------  <--parede\n";
			}
			
			cout << vetor[j];
			
			
			if(j == pivot){
				cout << "  <-- novo pivot";
			}
			
			cout << endl;
		}
		
		system("pause");
			
		}
		
		if(pivot == 0){
			
			// se o pivot atingir a posição 0 significa q o vetor está ordendado
			
			cout << "\n\n O vetor esta ordenando\n\n";
			
			return 0;
		}
		
		if(troca < pivot){
		
		swap(vetor[pivot],vetor[parede]);		//apos a varredura o pivot é movido para ao lado da parede
		
		for (j=0 ; j<6 ; j++){
						
			if(j == parede){
				cout << "-------  <--parede\n";
			}
			
			cout << vetor[j];
			
			
			if(j == parede){
				cout << "  <-- apos a varredura, o pivot e movido para o lado da parede";
			}
			
			cout << endl;
		}
		
		system("pause");
		
		parede = 0;
		
		cout << endl;
		
		for (j=0 ; j<6 ; j++){
						
			if(j == parede){
				cout << "-------  <--parede\n";
			}
			
			cout << vetor[j];
			
			
			if(j == pivot){
				cout << "  <-- novo pivot";
			}
			
			cout << endl;
		}
		
		system("pause");
		
		
		}		
		
	}
	
	return 0;
}
