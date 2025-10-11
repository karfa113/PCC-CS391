#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* rchild;
    Node* lchild;

    Node(int value){
        data = value;
        rchild = nullptr;
        lchild = nullptr;
    }
};

class BST{
private:
    Node* root;

    Node* insert(Node* node, int n){
        if(node == nullptr) 
            return new Node(n);
        else if(n > node->data)
            node->rchild = insert(node->rchild, n);
        else if(n < node->data)
            node->lchild = insert(node->lchild, n);

        return node;
    }

    void inorder(Node* node){
        if(node != nullptr){
            inorder(node->lchild);
            cout << node->data <<" ";
            inorder(node->rchild);
        }
    }

    void preorder(Node* node){
        if(node != nullptr){
            cout << node->data << " ";
            preorder(node->lchild);
            preorder(node->rchild);
        }
    }

    void postorder(Node* node){
        if(node != nullptr){
            postorder(node->lchild);
            postorder(node->rchild);
            cout << node->data << " ";
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void insert(int value){
        root = insert(root, value);
    }

    void displayInorder(){
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder(){
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder(){
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main(void){
    BST bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(1);
    bst.insert(45);
    bst.insert(42);
    bst.displayInorder();
    bst.displayPreorder();
    bst.displayPostorder();
    return 0;
}