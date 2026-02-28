#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(){
    int item;
    printf("Enter item to push: ");
    scanf("%d", &item);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Stack is full");
        return;
    }

    newNode->data = item;
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack is empty");
        return;
    }

    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void display(){
    if(top == NULL){
        printf("Stack is empty");
        return;
    }

    struct Node* temp = top;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(void){
    int choice;
    while(1){
        printf("-----------\n");
        printf("   Stack   \n");
        printf("-----------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("-----------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) push();
        if(choice == 2) pop();
        if(choice == 3) display();
        if(choice == 4) return 0;
        else continue;
    }
    return 0;
}