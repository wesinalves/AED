#include <iostream>
#include <cmath>
using namespace std;

int partition(int *entrada, int p, int r){
    int x = entrada[r];
    int i = p - 1;

    for(int j = p; j <= r - 1; j++){
        if(entrada[j] <= x){
            i++;
            swap(entrada[i], entrada[j]);
        }
    }
    swap(entrada[i + 1], entrada[r]);
    return i + 1;
}

void quickSort(int *entrada, int p, int r){
    if(p < r){
        //int q = floor((p + r) / 2); // calculamos o meio
        int q = partition(entrada, p, r); // calculamos o meio
        quickSort(entrada, p, q - 1);
        quickSort(entrada, q + 1, r);
    }
}

int main(){
    int n = 10;
    int e[n] = {0, 3, 1, 7, 9, 5, 4, 2, 10, 8};

    quickSort(e, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << e[i] << "\t";
    }

    cout << endl;

    return 0;
}
















