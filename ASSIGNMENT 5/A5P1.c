#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item){
    if(top == SIZE - 1){
        printf("Stack is FULL");
        exit(1);
    }else{
        stack[++top] = item;
    }
}

int pop(){
    if(top == -1){
        printf("Stack is empty");
        exit(1);
    }else{
        return stack[top--];
    }
}

int main(void){
    char postfix[SIZE];
    char ch;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    for(int i=0; postfix[i] != '\0'; i++){
        ch = postfix[i];

        if(ch >= '0' && ch <= '9'){
            push(ch - '0');
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            int first = pop();
            int second = pop();
            
            if(ch == '+') push(second + first);
            if(ch == '-') push(second - first);
            if(ch == '*') push(second * first);
            if(ch == '/') push(second / first);   
        }else{
            printf("Invalid expression");
        }
    }

    printf("Value: %d", pop());
    return 0;
}