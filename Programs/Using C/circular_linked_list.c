#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert();
void deleteNode(); 
void display();
void search();

int main(void){
    int choice;
    while(1){
        printf("\n\n--- Circular Linked List ---\n");
        printf("1. Insert at any position\n");
        printf("2. Delete from a position (kth from end)\n");
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
                deleteNode();
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
                printf("Invalid choice!");
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
    newNode->next = NULL;

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
        return;
    }

    struct Node* temp = head;
    int i = 1;
    while(i < pos - 1 && temp->next != head){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    int k;
    printf("Enter position from end to delete (k): ");
    scanf("%d", &k);

    int len = 1;
    struct Node* temp = head;
    while(temp->next != head){
        len++;
        temp = temp->next;
    }

    if(k > len || k <= 0){
        printf("Invalid position!\n");
        return;
    }

    int pos = len - k + 1; 
    if(pos == 1){
        struct Node* last = head;
        while(last->next != head)
            last = last->next;

        struct Node* del = head;
        if(head->next == head){ 
            head = NULL;
        }else{
            head = head->next;
            last->next = head;
        }
        free(del);
        printf("Deleted node from position %d (from end).\n", k);
        return;
    }

    temp = head;
    for(int i = 1; i < pos - 1; i++)
        temp = temp->next;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);
    printf("Deleted node from position %d (from end).\n", k);
}

void display(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

void search(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    int value;
    printf("Enter element to search: ");
    scanf("%d", &value);

    struct Node* temp = head;
    int pos = 1, found = 0;

    do{
        if(temp->data == value){
            printf("Element %d found at position %d.\n", value, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }while(temp != head);

    if(!found)
        printf("Element %d not found in the list.\n", value);
}
