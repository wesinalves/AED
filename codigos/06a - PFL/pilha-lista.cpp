#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int value){
        data = value;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;

    LinkedList(){
        head = NULL;
    }

    void addNode(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void insertNode(int pos, int value){
        Node* current = head;
        Node* newNode = new Node(value);

        for(int i = 0; i < pos - 1; i++){
            current = current->next;
            if(current == NULL){
                cout << "Index out range" << endl;
            }
        }

        newNode->next = current->next;
        current->next = newNode;


    }



    Node* search(int value){
        Node* temp = head;
        while(temp != NULL && temp->data != value){
            temp = temp->next;
        }
        return temp;
    }

    void deleteNode(int value){
        Node* temp1 = head;
        Node* temp2 = NULL;

        while(temp1 != NULL && temp1->data != value){
            temp2 = temp1;
            temp1 = temp1->next;
        }

        temp2->next = temp1->next;

        delete temp1;
    }

    void deleteHead(){
        Node* temp1 = head;
        head = temp1->next;

        delete temp1;
    }

    void printList(){
        if(head == NULL){
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << "\t";
            temp = temp->next;
        }

        cout << endl;

    }

};

class Stack {
    private:
    // int top = -1;
    // Node* head = NULL;
    LinkedList top;

    public:
    bool empty(){
        if(top.head == NULL){
            return true;
        }else{
            return false;
        }
    }
    void push(int value){
        top.addNode(value);
    }

    void pop(){
        top.deleteHead();
    }

    void printStack(){
        top.printList();
    }
};

int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.pop();

    stack.printStack();

    return 0;

}