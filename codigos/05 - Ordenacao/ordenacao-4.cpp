#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
using namespace std;

float randomFloat(int a, int b){
    float f;
    f = a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(b-1)));
    return f;
}

int main(){
    // inializar
    // gerar 100 alturas de forma aleatória
    int n = 100;
    float alturas[n];
    srand(time(NULL));
    cout << setprecision(2) << fixed;
    for(int i=0; i<n; i++){
        alturas[i] = randomFloat(1,3);
        cout << alturas[i] << "\t";
    }
    cout << endl;
    system("read -n1 -r -p 'Press any key to continue...' ");
    system("clear");

    // processar
    int continua = 1;
    while(continua == 1){
        continua = 0;
        for(int i=0; i < n-1; i++){
            if(alturas[i] > alturas[i+1]){
                swap(alturas[i], alturas[i+1]);
                continua = 1;
            }
        }
    }
   
    // finalizar
    for(int i=0; i<n; i++){
        cout << alturas[i] << "\t";
    }
    cout << endl;
    return 0;
}  