#include <iostream>
using namespace std;

int buscaSequencial(int array[], int size, int target){
    int i = 0;
    while(array[i] != target && i < size)
        i++;
    
    if(i >= size)
        return -1;
    else
        return i;
}

int main(){
    int myArray[] = {1,2,6,7,8,55,33,34,3,76,87};

    int result;

    result = buscaSequencial(myArray, 11, 87);

    cout << result << endl;

    return 0;
}