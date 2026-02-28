#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enQueue(){
    int item;
    printf("Enter item: ");
    scanf("%d", &item);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Queue is full");
        return;
    }

    newNode->data = item;
    newNode->next = NULL;

    if(rear == NULL){
        front = rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
}

void deQueue(){
    if(front == NULL){
        printf("Queue is empty");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is empty");
        return;
    }

    struct Node* temp = front;
    printf("Front -> ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" <- Rear");
    printf("\n");
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

        if(choice == 1) enQueue();
        if(choice == 2) deQueue();
        if(choice == 3) display();
        if(choice == 4) return 0;
        else continue;
    }
    return 0;
}