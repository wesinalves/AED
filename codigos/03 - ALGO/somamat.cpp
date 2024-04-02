#include <iostream>
#include <iomanip>
using namespace std;

int matrixSum(int **mat, int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            total += mat[i][j];
        }
    }
    return total;
}

int main(){
    // initial
    const int N = 2000;
    int result;
    int **myArray = new int *[N];
    for(int i = 0; i < N; i++){
        myArray[i] = new int[N];
    }

    int number;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            number = rand() % 100;
            myArray[i][j] = number; // random number 0 to 100
        }
    }

    // set clock
    clock_t start, end;
    start = clock();
    
    // processing
    result = matrixSum(myArray, N);
    cout << "Total sum is: " << result << endl;

    // terminate
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << setprecision(5) << fixed;
    cout << time_taken << " sec" << endl;

}