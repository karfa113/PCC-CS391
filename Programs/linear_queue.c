#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10

int queue[SIZE];
int front = -1;
int rear = -1;

void insert() {
    int item;
    printf("Enter item to be inserted: ");
    scanf("%d", &item);
    if (rear == SIZE - 1) printf("Overflow ! can't insert\n");
    else{
        if(front == -1) front = 0;
        queue[++rear] = item;
    }
}

int delete(){
    int val;
    if(front == -1 || front > rear){
        printf("Underflow ! can't delete");
        return -1;
    }else{
        val = queue[front];
        front ++;
        if(front > rear) front = rear = -1;
        return val;
    }
}

int peek(){
    if(front == -1 || front > rear){
        printf("Queue is empty");
        return -1;
    }else{
        return queue[front];
    }
}

void display(){
    if(front == -1 || front > rear) printf("Queue is empty");
    else{
        printf("Queue Elements: ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
    }
}

int main(void){
    int choice, value;
    while(1){
        printf("\n**** Queue Operation ****\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Peek\n");
        printf("4. Display queue\n");
        printf("5. EXIT\n");
        printf("*************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 5) break;

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                value = delete();
                if(value != -1) printf("The number deleted is: %d\n", value);
                break;
            case 3:
                value = peek();
                if(value != -1) printf("The first value in the queue is: %d\n", value);
                break;
            case 4:
                display();
                break;
            default:
                printf("\n Not a valid choice !");
                break;
        }
    }

    printf("Exiting ...");
    return 0;
}