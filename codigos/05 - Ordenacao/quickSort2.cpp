#include <iostream>
using namespace std;

int partition(int *vetor, int inicio, int fim){
    int x = vetor[fim];
    int i = inicio - 1;
    for(int j = inicio; j <= fim - 1; j++){
        if(vetor[j] <= x){
            i++;
            swap(vetor[i], vetor[j]);
        }
    }
    swap(vetor[i + 1], vetor[fim]);

    return i + 1;
}

void quickSort(int *vetor, int inicio, int fim){
    if(inicio < fim){
        int q = partition(vetor, inicio, fim);
        quickSort(vetor, inicio, q - 1);
        quickSort(vetor, q + 1, fim);
    }
}

int main(){
    int n = 8;
    int e[] = {0, 3, 1, 7, 9, 5, 4, 2};

    quickSort(e, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << e[i] << "\t";
    }

    cout << endl;

    return 0;
}