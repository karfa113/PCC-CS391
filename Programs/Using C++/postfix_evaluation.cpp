#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isOperator(char op){
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

string postfixEvaluation(string postfix){
    stack<char> st;
    string postfix = "";

    for(int i=0; i<postfix.length(); i++){
        char element = postfix[i];

        if(isalnum(element)) st.push(element);
        if(isOperator(element)){
            int op2 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            char new = 
        }
    }
}