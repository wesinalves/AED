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
        Node* prev = NULL;
        Node* current = head;
        Node* newNode = new Node(value);

        for(int i = 0; i < pos; i++){
            prev = current;
            current = current->next;
            if(current == NULL and i < pos){
                cout << "Index out of range" << endl;
                return;
            }
        }

        newNode->next = current;
        prev->next = newNode;\

        return;


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

int main(){
    LinkedList list;
    Node* x;

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);
    list.addNode(40);
    list.addNode(50);

    list.printList();

    list.insertNode(3, 40);

    list.printList();

    return 0;

}