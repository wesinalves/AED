#include <iostream>
using namespace std;

int buscaBinaria(int array[], int size, int target);

int main(){
    int N, result, target;
    cout << "Digite o número de elementos: ";
    cin >> N;
    int myArray[N];

    cout << "Digite os elementos do vetor: "; 
    for(int i = 0; i < N; i++){
        cin >> myArray[i];
    }

    cout << "Digite o alvo a ser pesquisado: ";
    cin >> target;

    result = buscaBinaria(myArray, N, target);

    cout << result;

    return 0;
}

int buscaBinaria(int array[], int size, int target){
    int l = 0;
    int r = size - 1;
    int m;

    while(l <= r){
        m = (l+r) / 2;
        if(array[m] == target){
            return m;
        }
        else if(array[m] <= target){
            l = m + 1;
        }
        else{
            r = m - 1;  
        }
    }

    return -1;
}