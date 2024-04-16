#include <iostream>
#include <cmath>
using namespace std;

void merge(int *entrada, int p, int q, int r){
    int n1, n2;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];

    for(int i = 0; i < n1; i++){
        L[i] = entrada[p + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = entrada[q + j + 1];
    }

    L[n1] = 1000000;
    R[n2] = 1000000;

    int i = 0;
    int j = 0;

    for(int k = p; k <= r; k++){
        if(L[i] <= R[j]){
            entrada[k] = L[i];
            i++;
        }else{
            entrada[k] = R[j];
            j++;
        }
    }

}

void mergeSort(int *entrada, int p, int r){
    if(p < r){
        //int q = floor((p + r) / 2); // calculamos o meio
        int q = (p + r) / 2; // calculamos o meio
        mergeSort(entrada, p, q);
        mergeSort(entrada, q + 1, r);
        merge(entrada, p, q, r);
    }
}

int main(){
    int n = 8;
    int e[] = {0, 3, 1, 7, 9, 5, 4, 2};

    mergeSort(e, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << e[i] << "\t";
    }

    cout << endl;

    return 0;
}
















