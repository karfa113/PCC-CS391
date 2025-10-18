#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* head = NULL;

void insertBegining(){
	int value;
	printf("Enter value to insert: ");
	scanf("%d", &value);

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		printf("Memory allocation failed\n");
		return;
	}
	
	newNode->data = value;
	newNode->next = head;
	head = newNode;
}

void insertEnd(){
	int value;
	printf("Enter value to insert: ");
	scanf("%d", &value);
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		printf("Memory allocation failed\n");
		return;
	}
	
	newNode->data = value;
	newNode->next = NULL;
		
	if(head == NULL){
		head = newNode;
		return;
	}else{
		struct Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void insertatPos(){
		
}
