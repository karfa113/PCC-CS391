#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char ch){
    if(ch == '*' || ch == '/') return 2;
    if(ch == '+' || ch == '-') return 1;
    else return 0;
}

bool isOperator(char op){
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

string infixToPostfix(string infix){
    stack<char> st;
    string postfix = "";

    for(int i=0; i<infix.length(); i++){
        char element = infix[i];

        if(element == ' ') continue;
        if(isalnum(element)) postfix+=element;
        if(element == '(') st.push(element);

        if(element == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop();
        }

        if(isOperator(element)){
            while(!st.empty() && precedence(st.top()) >= precedence(element)){
                if(st.top() == '(') break;
                postfix += st.top();
                st.pop();
            }
            st.push(element);
        }
    }

    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main(void){
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}