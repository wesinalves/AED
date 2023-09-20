#include <iostream>
using namespace std;

int buscaBinaria(int v[], int t, int a);

int main(){
    int vet[50];
    int alvo;
    int tamanho = 10;
    int resultado;
    // initializar vetor
    for(int i = 0; i < tamanho; i++){
        vet[i] = i * 3;
    }
    // apresentar vetor
    cout << "Vetor a ser pesquisado: " << endl;
    for(int i=0; i<tamanho; i++){
        cout << vet[i] << "\t";
    }
    cout << endl;
    // realizar a busca
    while(1){
        cout << "Digite o alvo a ser pesquisado." << endl;
        cin >> alvo;
        resultado = buscaBinaria(vet, tamanho, alvo);
        // imprimir resultado
        if (resultado == -1){
            cout << "Elemento não encontrado." << endl;
        }else{
            cout << "Elemento encontrado na posição: " << resultado << endl;
        }
        if(alvo == -1)
            break;
    }
    

    return 0;
}

int buscaBinaria(int v[], int t, int a){
    int l, r, m;
    l = 0;
    r = t - 1;
    while(l < r){
        m = (l + r) / 2;
        if(v[m] < a){
            l = m + 1;
        }else{
            r = m;
        }
    }
    if(v[r] == a)
        return r;
    return -1;
}

int buscaBinaria2(int v[], int t, int a){
    int l, r, m;
    l = 0;
    r = t - 1;
    while(l <= r){
        m = (l + r) / 2;
        if(v[m] == a){
            return m;
        }else if(v[m] <= a){
            l = m + 1;
        }else{
            r = m - 1;
        }
    }
    return -1;
}