#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(){
    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full");
        return;
    }

    newNode->data = item;
    newNode->next = front;

    if(front == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty");
        return;
    }

    if(front == rear){
        free(front);
        front = rear = NULL;
    }else{
        struct Node* temp = front;
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        printf("Queue is empty");
        return;
    }

    struct Node* temp = front;
    while(temp->next != front){
        printf("%d", temp->data);
        temp=temp->next;
    }
    printf("%d", rear->data);
}

int main(void){
    int choice;
    while(1){
        printf("-----------\n");
        printf("   Queue   \n");
        printf("-----------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("-----------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) enqueue();
        if(choice == 2) dequeue();
        if(choice == 3) display();
        if(choice == 4) return 0;
        else continue;
    }
    return 0;
}