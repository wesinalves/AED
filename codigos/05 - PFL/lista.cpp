#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // Default constructor
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
    // default constructor
    LinkedList(){
        head = NULL;
    }

    void append(int value){
        Node* newNode = new Node(value);

        if(head == NULL){
            head = newNode;
            return;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }


    void deleteItem(int offset){
        // we need 2 temporary nodes
        Node *temp1 = head, *temp2 = NULL;

        int len = length();

        // validate the position offset
        if (len < offset){
            cout << "Index out of range" << endl;
            return;
        }

        // delete head if the case
        if (offset == 0){
            head = head->next;

            // delete old head
            delete temp1;
            return;
        }
        
        // traverse the list until the position
        while(offset-- > 0){
            temp2 = temp1;
            temp1 = temp1->next;
        }

        // temp2 is the previous position
        temp2->next = temp1->next;

        delete temp1;

    }

    void insert(int value, int offset){
        // we need 2 temporary nodes
        Node *temp1 = head, *temp2 = NULL;
        Node* newNode = new Node(value);

        int len = length();

        // validate the position offset
        if (len < offset){
            cout << "Index out of range" << endl;
            return;
        }
        
        while(--offset > -1){
            temp2 = temp1;
            temp1 = temp1->next;
        }

        // temp2 is the previous position
        newNode->next = temp1;
        temp2->next = newNode;

    }

    int length(){
        Node* temp = head;
        int listLength = -1;

        while(temp != NULL){
            temp = temp->next;
            listLength++;
        }

        return listLength;
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

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);
    
    cout << "head of list is " << list.head->data << endl;

    list.printList();

    list.deleteItem(0);

    list.insert(35, 2);

    list.printList();

    return 0;
}