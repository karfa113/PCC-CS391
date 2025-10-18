#include<iostream>
using namespace std;
#define MAX 5

class Stack{
private:
    int arr[MAX];
    int top;
public:
    Stack(){
        top = -1;
    }

    bool isFull(){
        return (top == MAX - 1);
    }

    bool isEmpty(){
        return (top == -1);
    }

    void peek(){
        if(isEmpty())
            cout << "Stack is empty !" << endl;
        else
            cout << "Top element is: " << arr[top] << endl;
    }
    

    void push(int item){
        if(isFull()){
            cout << "Stack Overflow ! can't push" << endl;
            return;
        }
        arr[++top] = item;
        cout << item << " pushed into the stack" << endl;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack Underflow ! can't pop" << endl;
            return;
        }
        cout << arr[top] << " is removed from the stack" << endl;
        top--;
    }

    void display(){
        if(isEmpty()){
            cout << "Stack is empty ! nothing to display" << endl;
            return;
        }
        cout << "Stack elements: ";
        for(int i=top; i>=0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main(void){
    Stack s;
    int choice, item;

    while(true){
        cout << "------ Stack operation ------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check is the stack is empty" << endl;
        cout << "5. Check if the stack is full" << endl;
        cout << "6. Display the stack" << endl;
        cout << "7. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter item to push: ";
                cin >> item;
                s.push(item);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                if(s.isEmpty())
                    cout << "Stack is empty !";
                else
                    cout << "Stack is not empty";
                break;

            case 5:
                if(s.isFull())
                    cout << "Stack is full";
                else
                    cout << "Stack is not full";
                break;

            case 6:
                s.display();
                break;

            case 7:
                cout << "Exiting program ...";
                return 0;

            default:
                cout << "Please enter a valid choice !";
                continue;
        }
    }
}