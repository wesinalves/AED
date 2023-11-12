#include <iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;
    Node* parent;
    char color;

    Node(){
        key = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = 'b';
    }

    Node(int value){
        key = value;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = 'r';
    }
};

class RBTree{
    public:
    Node* root;

    RBTree(){
        root = NULL;
    }

    void printTree(Node* node, string indent = "", bool last = true) {
        if (node != NULL) {
            cout << indent;
            if(node == root){
                cout << "--->";
                indent += "     ";
            }else{
                if (last) {
                cout << "R----";
                indent += "     ";
                } else {
                    cout << "L----";
                    indent += "|    ";
                }
            }
            cout << node->key << "(" << node->color << ")" << endl;
            printTree(node->left, indent, false);
            printTree(node->right, indent, true);
    }
}

    void leftRotate(Node* x){
        Node* y = x->right;
        x->right = y->left;
        if(y->left != NULL)
            y->left->parent = x;
        y->parent = x->parent;
        if(x->parent == NULL){
            root = y;
        }else if(x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y){
        Node* x = y->left;
        y->left = x->right;
        if(x->right != NULL)
            x->right->parent = y;
        x->parent = y->parent;
        if(y->parent == NULL){
            root = x;
        }else if(y == y->parent->left){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    void insert(int value){
        Node* z = new Node(value);
        Node* y = NULL;
        Node* x = root;

        while(x != NULL){
            y = x;
            if(z->key < x->key){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        z->parent = y;
        if(y == NULL){
            root = z;
        }else if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
        z->left = NULL;
        z->right = NULL;
        z->color = 'r';
        insertFixup(z); 
    }

    void insertFixup(Node* z){
        Node* y;
        while(z->parent != NULL and z->parent->color == 'r'){
            if(z->parent == z->parent->parent->left){
                y = z->parent->parent->right;
                if(y != NULL and y->color == 'r'){
                    z->parent->color = 'b';
                    y->color = 'b';
                    z->parent->parent->color = 'r';
                    z = z->parent->parent;
                }else{
                    if(z == z->parent->right){
                        z = z->parent;
                        leftRotate(z);
                    } 
                    z->parent->color = 'b';
                    z->parent->parent->color = 'r';
                    rightRotate(z->parent->parent);
                }
                
            }else if(z->parent == z->parent->parent->right){
                y = z->parent->parent->left;
                if(y != NULL and y->color == 'r'){
                    z->parent->color = 'b';
                    y->color = 'b';
                    z->parent->parent->color = 'r';
                    z = z->parent->parent;
                }else{
                    if(z == z->parent->left){
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = 'b';
                    z->parent->parent->color = 'r';
                    leftRotate(z->parent->parent);
                } 
                    
            }
        }
        root->color = 'b';
    }

    void transplant(Node*u, Node* v){
        if(u->parent == NULL){
            root = v;
        }else if(u == u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    Node *minimum(Node* x){
        while(x->left != NULL){
            x = x->left;
        }
        return x;
    }

    void remove(Node* z){
        Node* y = z;
        Node* x;
        char yOriginalColor = y->color;
        if(z->left == NULL){
            x = z->right;
            transplant(z,z->right);
        }else if(z->right == NULL){
            x = z->left;
            transplant(z,z->left);
        }else{
            yOriginalColor = y->color;
            x = y->right;
            if(y->parent == z){
                x->parent = y;
            }else{
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z,y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        if(yOriginalColor == 'b'){
            removeFixup(x);
        }
    }

    void removeFixup(Node* x){
        Node* w;
        while(x != NULL and x->color == 'b'){
            if(x == x->parent->left){
                w = x->parent->right;
            }
            if(w->color == 'r'){
                w->color = 'b';
                x->parent->color = 'r';
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == 'b' and w->right->color == 'b'){
                w->color = 'r';
                x = x->parent;
            }else if(w->right->color = 'b'){
                w->left->color = 'b';
                w->color = 'r';
                rightRotate(w);
                w = x->parent->right;
            }
        }
    }
};

int main(){
    RBTree myTree;

    myTree.insert(1);
    myTree.insert(2);
    myTree.insert(4);
    myTree.insert(5);
    myTree.insert(7);
    myTree.insert(8);
    myTree.insert(11);
    myTree.insert(14);
    myTree.insert(15);


    myTree.printTree(myTree.root);
    cout << endl;
}