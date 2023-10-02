#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    // inializacao
    int menor;
    int aux;
    int tamanho = 10;
    int A[tamanho];
    for(int j=0; j<tamanho; j++){
        A[j] = rand() % 100;
        cout << A[j] << "\t";
        
    }
    cout << endl;
    // processmento
    for(int i = 0; i < tamanho - 1; i++){
        menor = i;
        for(int j = i + 1; j < tamanho; j++){
            if(A[j] < A[menor]){
                menor = j;
            }
        }
        // troca elementos
        aux = A[i];
        A[i] = A[menor];
        A[menor] = aux;
    }
    // finalizacao
    for(int j=0; j<tamanho; j++){
        cout << A[j] << "\t";
        
    }
    cout << endl;
    return 0;
}