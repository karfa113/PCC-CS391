#include<iostream>
using namespace std;
#define MAX 5

class Stack{
private:
    int arr[MAX];
    int front;
    int rear;
public:
    Stack(){
        front = rear = -1;
    }

    bool isEmpty(){
        return (front == -1 || front > rear);
    }

    bool isFull(){
        return rear == MAX - 1;
    }

    void enQueue(int item){
        if(isFull()){
            cout << "Overflow ! cant insert" << endl;
            return;
        }
        if(front == -1) front = 0;
        rear++;
        arr[rear] = item;
    }

    int deQueue(){
        if(isEmpty()){
            cout << "Underflow ! can't insert" << endl;
            return -1;
        }
        int deletedItem = arr[front];
        front++;
        return deletedItem;
    }

    int peek(){
        if(isEmpty()){
            cout << "Queue is empty !" << endl;
            return -1;
        }
        return arr[front];
    }

    void display(){
        
    }
};