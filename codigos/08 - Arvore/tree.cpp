#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node(){
        key = 0;
        left = NULL;
        right = NULL;
    }

    Node(int value){
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    public:
    Node* root;

    BinaryTree(){
        root = NULL;
    }

    void inOrderTreeWalk(Node* x){
        if(x != NULL){
            inOrderTreeWalk(x->left);
            cout << x->key << "\t";
            inOrderTreeWalk(x->right);
        }
    }
};

int main(){
    BinaryTree myTree;

    myTree.root = new Node(6);

    myTree.root->left = new Node(5);
    myTree.root->left->left = new Node(2);
    myTree.root->left->right = new Node(5);
    
    myTree.root->right = new Node(7);
    myTree.root->right->right = new Node(8);

    myTree.inOrderTreeWalk(myTree.root);
    cout << endl;
}