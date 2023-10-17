#include <iostream>
#define length 5

using namespace std;

class Stack{
    private:
    int top = -1;
    int elements[length];

    public:
    bool empty(){
        if (top == -1){
            return true;
        }else{
            return false;
        }
    }

    void push(int item){
        if(top < length - 1){
            top++;
            elements[top] = item;
            cout << top << endl;
        }else{
            cout << "stack overflow" << endl;
        }
    }

    int pop(){
        if(empty()){
            cout << "stack underflow" << endl;
            return 0;
        }else{
            top--;
            return elements[top + 1];
        }
    }

    void printStack(){
        for(int i = 0; i <= top; i++){
            cout << elements[i] << " <- " << "\t";
        }
        cout << endl;
    }
};

int main(){

    // create options menu
    Stack s;
    int option = 1;
    int value;
    while(option != 4){
        cout << "Selecione uma opção" << endl;
        cout << "[1] - inserir elemento na pilha" << endl;
        cout << "[2] - remover elemento na pilha" << endl;
        cout << "[3] - imprimir elementos da pilha" << endl;
        cout << "[4] - sair" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                /* code */
                cout << "digite o valor a ser inserido na pilha" << endl;
                cin >> value;
                s.push(value);
                break;
            case 2:
                value = s.pop();
                cout << "[" << value << "]" << endl;
                break;
            case 3:
                s.printStack();
            default:
                break;
        }
    }

    return 0;
}