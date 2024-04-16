#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    // inicializacao
    int chave, i;
    int tamanho = 10;
    int A[] = {2 ,4 ,1, 10, 3, 5, 4, 12, 8, 9};

    for(int j = 0; j < tamanho; j++){
        A[j] = rand() % 100;
        cout << A[j] << "\t";
    }
    cout << endl;
    // processamento
    for(int j = 1; j < tamanho; j++){
        chave = A[j];
        i = j - 1;
        while(i>=0 && A[i] > chave){
            A[i + 1] = A[i];
            i = i -1;
        }
        A[i+1] = chave;
    }

    // finalizacao
    for(int j = 0; j < tamanho; j++){
        cout << A[j] << "\t";
    }
    cout << endl;
}