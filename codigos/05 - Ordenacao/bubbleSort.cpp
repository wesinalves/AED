#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(){
    // inicializar
    int n = 10;
    int A[n];
    srand(time(NULL));
    for(int i=0; i<n; i++){
        A[i] = rand() % 10;
        cout << A[i] << "\t";
    }
    cout << endl;

    // processar
    int tamanho = n;
    int continua = 1;
    while(continua){
        continua = 0;
        for(int j=0; j < tamanho - 1; j++){
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]); // troca elementos adjacentes
                continua = 1;
            }
        }
        //tamanho--;
    }
    cout << "###############################" << endl;
    // finalizar
    for(int i = 0; i < n; i++){
        cout << A[i] << "\t";
    }

    return 0;
}