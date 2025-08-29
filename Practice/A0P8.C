// Write a c program to reverse a string using stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

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

char pop(){
    if(top == -1){
        printf("Stack is empty");
        exit(1);
    }else{
        return stack[top--];
    }
}

int main(void){
    char string[SIZE];
    printf("Enter the string: ");
    scanf("%s", string);

    for(int i=0; string[i] != '\0'; i++){
        push(string[i]);
    }

    printf("Reversed string: ");
    for(int i=0; stack[i] != '\0'; i++){
        printf("%c", pop());
    }

    return 0;
}