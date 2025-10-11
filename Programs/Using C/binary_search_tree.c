#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* rchild;
    struct Node* lchild;
};

struct Node* newNode(int n){
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp != NULL){
        temp->data = n;
        temp->rchild = NULL;
        temp->lchild = NULL;
    }
    return temp;
}

struct Node* insert(struct Node* root, int x){
    if(root == NULL) 
        return newNode(x);
    else if(x > root->data)
        root->rchild = insert(root->rchild, x);
    else
        root->lchild = insert(root->lchild, x);

    return root;
};

void inOrder(struct Node* root){
    if(root == NULL) return;
    inOrder(root->lchild);
    printf("%d ", root->data);
    inOrder(root->rchild);
}

void preOrder(struct Node* root){
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}

void postOrder(struct Node* root){
    if(root == NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    printf("%d ", root->data);
}

int main(void){
    struct Node* root = NULL;
    root = newNode(10);
    insert(root, 5);
    insert(root, 1);
    insert(root, 45);
    insert(root,42);
    printf("Inorder: ");
    inOrder(root);
    printf("\nPreorder: ");
    preOrder(root);
    printf("\nPostorder: ");
    postOrder(root);
    printf("\n");
    return 0;
}