#include<stdio.h>
#include<stdlib.h>
int sum = 0;

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
    sum = sum + root->data;
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

int findMax(struct Node* root){
	if(root == NULL){
		printf("Tree is empty\n");
		return -1;
	}
	struct Node* current  = root;
	while(current->rchild != NULL){
		current = current->rchild;
	}
	return current->data;
}

int findMin(struct Node* root){
	if(root == NULL){
		printf("Tree is empty\n");
		return -1;
	}
	struct Node* current = root;
	while(current->lchild != NULL){
		current = current->lchild;
	}
	return current->data;
}

struct Node* search(struct Node* root, int key){
	if(root == NULL || root->data == key)
		return root;
	if(key > root->data)
		return search(root->rchild, key);
	else
		return search(root->lchild, key);
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
    
    printf("Maximum value: %d\n", findMax(root));
    printf("Minimum value: %d\n", findMin(root));
    
    int key = 42;
    struct Node* result = search(root, key);
    if(result == NULL){
    	printf("%d is not in the tree\n", key);
    }else{
    	printf("%d is in the tree\n", key);
    }
    
    printf("Sum of all the elements of the tree: %d\n", sum);
    return 0;
}
