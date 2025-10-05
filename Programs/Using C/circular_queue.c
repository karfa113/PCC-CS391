#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int isFUll(){
    if ((front == (rear + 1) % MAX) || (front == -1 && rear == MAX - 1))
        return 1;
    return 0;
}

void enQueue(int item){
    if (isFUll()){
        printf("Overflow ! Can't insert");
    }
    else{
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = item;
        printf("Element inserted");
    }
}

void deQueue(){
    if (front == -1)
        printf("Underflow ! can't remove");
    else{
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        printf("Element deleted");
    }
}

void peek(){
    if (front == -1)
        printf("Queue is empty !");
    else{
        printf("Front: %d\n", queue[front]);
        printf("Rear: %d", queue[rear]);
    }
}

void display(){
    if (front == -1)
        printf("Queue is empty !");
    else{
        printf("Queue elements: ");
        for(int i=front; i != rear; i= (i+1)%MAX){
            printf("%d ", queue[i]);
        }
        printf("%d", queue[rear]);
    }
}

int main(){
    int choice;
    while (1){
        printf("\n***** Circular Queue *****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("****************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1){
            int val;
            printf("Enter number: ");
            scanf("%d", &val);
            enQueue(val);
        }else if (choice == 2){
            deQueue();
        }else if (choice == 3){
            peek();
        }else if (choice == 4){
            display();
        }else if (choice == 5){
            break;
        }else{
            printf("Invalid choice !");
            continue;
        }
    }

    return 0;
}