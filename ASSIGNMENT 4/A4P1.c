#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item){
    if(top == SIZE - 1){
        printf("Stack is Full");
    }else{
        stack[++top] = item;
    }
}

char pop(){
    if(top == -1){
        printf("Stack is empty");
        return '\0';
    }else{
        return stack[top--];
    }
}

int precedence(char ch){
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '(') return 0;
    return -1;
}

int main(void){
    char infix[SIZE];
    char postfix[SIZE];
    char ch;
    int i=0, j=0;
    printf("Enter the infix expression: ");
    scanf("%s", infix);
    
    for(i=0; infix[i] != '\0'; i++){
        ch = infix[i];

        if(isalnum(ch)){
            postfix[j++] = ch;
        }else if(ch == '('){
            push(ch);
        }else if(ch == ')'){
            while(top != -1 && stack[top] != '('){
                postfix[j++] = pop();
            }
            pop();
        }else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            while(top != -1 && precedence(stack[top]) >= precedence(ch)){
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(top != -1){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
    return 0;
}