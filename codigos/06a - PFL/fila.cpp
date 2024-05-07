#include <iostream>
#define length 5

using namespace std;

class Queue{
    private:
    int head;
    int tail;
    int elements[length];

    public:
    void setHead(int value){
        head = value;
    }
    void setTail(int value){
        tail = value;
    }
    bool empty(){
        if (tail == head){
            return true;
        }else{
            return false;
        }
    }

    void enqueue(int item){
        elements[tail] = item;
        if(tail == length - 1){
            tail = 0;
        }else{
            tail += 1;
        }
        
    }

    int dequeue(){
        int x = elements[head];
        if(head == length - 1){
            head = 0;
        }else{
            head += 1;
        }
        return x;
    }

    void printQueue(){
        int index = head;
        for(int i = head; i < head + length ; i++){
            if(i == length){
                index = 0;
            }
            
            cout << elements[index] << " <- " << "\t";

            index++; 
            if(index == tail){
                break;
            }else if(tail == 0 && i == length - 1){
                break;
            }
        }
        cout << endl;
    }
};

int main(){

    // create options menu
    Queue s;
    s.setHead(0);
    s.setTail(0);
    int option = 1;
    int value;
    while(option != 4){
        cout << "Selecione uma opção" << endl;
        cout << "[1] - inserir elemento na fila" << endl;
        cout << "[2] - remover elemento na fila" << endl;
        cout << "[3] - imprimir elementos da fila" << endl;
        cout << "[4] - sair" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                /* code */
                cout << "digite o valor a ser inserido na fila" << endl;
                while(cin >> value){
                    if(value == -500){
                        break;
                    }
                    s.enqueue(value);
                }
                break;
            case 2:
                value = s.dequeue();
                cout << "[" << value << "]" << endl;
                break;
            case 3:
                s.printQueue();
            default:
                break;
        }
    }

    return 0;
}