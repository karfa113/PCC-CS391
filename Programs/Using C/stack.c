#include<stdio.h>
#define size 5

int stack[size];
int top = -1;

void push(int item){
    if (top == size-1){
        printf("Stack is FULL");
    }else{
        top++;
        stack[top] = item;
        printf("Success");
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty");
    }else{
        top--;
        printf("Success");
    }
}

void display(){
    if (top == -1){
        printf("Stack is empty");
    }else{
        printf("Stack elements: \n");
        for(int i=top; i>=0; i--){
            printf("%d ", stack[i]);
        }
    }
}

int main(void){
    int choice, item;
    while (1){
        printf("\n******************************\n");
        printf("        Stack Operation       \n");
        printf("******************************\n");
        printf("1. Push Item \n2. Pop Item \n3. Display Stack \n4. Exit\n");
        printf("******************************\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        if (choice == 1){
            printf("Enter the item: ");
            scanf("%d", &item);
            push(item);
        }else if (choice == 2){
            pop();
        }else if (choice == 3){
            display();
        }else{
            break;
        }
    }
    return 0;
}