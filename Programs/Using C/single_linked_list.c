#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning();
void insertEnd();
void insertPos();
void deleteBeginning();
void deleteEnd();
void display();
void search();
void reverse();

int main(void){
    int choice;

    while (1){
        printf("\n\n--- Single Linked List ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Display the linked list\n");
        printf("7. Search any element\n");
        printf("8. Reverse the linked list\n");
        printf("9. End\n");
        printf("----------------------------\n");
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            insertBeginning();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            insertPos();
            break;
        case 4:
            deleteBeginning();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            display();
            break;
        case 7:
            search();
            break;
        case 8:
            reverse();
            break;
        case 9:
            printf("Exiting program ...\n");
            exit(0);
        default:
            printf("Invalid Choice ! try again");
        }
    }

    return 0;
}

void insertBeginning(){
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node with value %d is inserted at the beginning", value);
}

void insertEnd(){
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }else{
        struct Node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with value %d inserted at the end", value);
}

void insertPos(){
    int value, pos, i = 1;
    printf("Enter the postition to insert at: ");
    scanf("%d", &pos);

    if (pos < 1){
        printf("Invalid position\n");
        return;
    }

    if(pos == 1){
        insertBeginning();
        return;
    }

    struct Node *temp = head;
    while (i < pos - 1 && temp != NULL){
        temp = temp->next;
        i++;
    }

    if (temp == NULL){
        printf("Position %d is out of bounds", pos);
        return;
    }

    printf("Enter the value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node with value %d inserted at position %d\n", value, pos);
}

void deleteBeginning(){
    if (head == NULL){
        printf("List is empty ! nothing to delete");
        return;
    }

    struct Node *temp = head;
    int deletedvalue = temp->data;
    head = head->next;
    free(temp);
    printf("Node with vlaue %d deleted from beginning", deletedvalue);
}

void deleteEnd(){
    if (head == NULL){
        printf("List is empty ! nothing to delete");
        return;
    }

    if (head->next == NULL){
        int deletedValue = head->data;
        free(head);
        head = NULL;
        printf("Node with value %d deleted form the end\n", deletedValue);
        return;
    }

    struct Node *secondLast = head;
    while (secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }

    struct Node *lastNode = secondLast->next;
    int deletedValue = lastNode->data;
    secondLast->next = NULL;
    free(lastNode);
    printf("Node with value %d deleted from the end\n", deletedValue);
}

void display(){
    if (head == NULL){
        printf("List is empty !");
        return;
    }

    struct Node *temp = head;
    printf("List elements: head -> ");
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(){
    int key, pos = 1;
    printf("Enter the key: ");
    scanf("%d", &key);

    struct Node *temp = head;
    while (temp->next != NULL){
        if (temp->data == key){
            printf("Element found at pos %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element not found in the list\n");
}

void reverse(){
    if (head == NULL || head->next == NULL){
        printf("List is empty or has only one element, no need to reverse !");
        return;
    }

    struct Node *prevNode = NULL, *currentNode = head, *nextNode = NULL;
    while (currentNode != NULL){
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
    printf("Reversed successfully");
    display();
}