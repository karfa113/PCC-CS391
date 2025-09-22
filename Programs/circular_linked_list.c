#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert();
void delete();
void display();
void search();

int main(void){
    int choice;
    while(1){
        printf("\n\n--- Circular Linked List ---\n");
        printf("1. Insert at any position\n");
        printf("2. Deleter from a position\n");
        printf("3. Display the list\n");
        printf("4. Search an element\n");
        printf("5. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice(1-5): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                printf("Exiting program ...\n");
                exit(0);
            default:
                printf("Invlid choice!");
        }
    }

    return 0;
}

void insert(){
    int value, pos;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter the position: ");
    scanf("%d", &pos);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    if(pos == 1){
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }else{
        int i=1;
        struct Node* temp = head;
        while(i<pos-1 && temp->next != NULL){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode; 
    }
}

void delete(){
    
}