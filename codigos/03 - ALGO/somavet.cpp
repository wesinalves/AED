#include <iostream>
#include <iomanip>
using namespace std;

int arraySum(int array[], int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += array[i];
    }
    return total;
}

int main(){
    // initial
    const int N = 20;
    int result;
    int myArray[N];
    for(int j = 0; j < N; j++){
        myArray[j] = rand() % 100; // random number 0 to 100
    }

    // set clock
    clock_t start, end;
    start = clock();
    
    // processing
    result = arraySum(myArray, N);
    cout << "Total sum is: " << result << endl;

    // terminate
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << setprecision(5) << fixed;
    cout << time_taken << " sec" << endl;

}