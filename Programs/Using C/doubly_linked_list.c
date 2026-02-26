#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};
struct Node* head = NULL;

void insertBeg(){
	int value;
	printf("Enter the value to insert: ");
	scanf("%d", &value);
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		printf("Memory allocation failed !");
		return;
	}
	
	newNode->data = value;
	newNode->prev = NULL;
	if(head == NULL){
		newNode->next = NULL;
		head = newNode;
	}else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void insertEnd(){
	int value;
	printf("Enter the value to insert: ");
	scanf("%d", &value);
	
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		printf("Memory allocation failed !");
		return;
	}
	
	newNode->next = NULL;
	newNode->data = value;
	if(head == NULL){
		newNode->prev = NULL;
		head = newNode;
	}else{
		struct Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}

void insertPos(){
	int pos;
	printf("Enter the position: ");
	scanf("%d", &pos);
	
	if(pos < 1){
		printf("Invalid position");
		return;
	}
	
	if(pos == 1){
		insertBeg();
		return;
	}
	
	int i=1;
	struct Node* temp = head;
	while(i<pos-1 && temp != NULL){
		temp = temp->next;
		i++;
	}
	
	if(temp == NULL){
		printf("Position is out of bounds");
		return;
	}
	
	int value;
	printf("Enter value to insert: ");
	scanf("%d", &value);
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL){
		printf("Memory allocation failed");
		return;
	}
	newNode->data = value;
	newNode->next = temp->next;
	newNode->prev = temp;
	
	if(temp->next != NULL){
		temp->next->prev = newNode;
	}
	temp->next = newNode;
}

void deleteBeg(){
	if(head == NULL){
		printf("List is empty");
		return;
	}
	
	if(head->next == NULL){
		free(head);
		head = NULL;
		return;
	}
	
	struct Node* del = head;
	head = head->next;
	head->prev = NULL;
	free(del);
}

void deleteEnd(){
	if(head == NULL){
		printf("List is empty");
		return;
	}
	
	if(head->next == NULL){
		free(head);
		head = NULL;
		return;
	}
	
	struct Node* del = head;
	while(del->next != NULL){
		del = del->next;
	}
	del->prev->next = NULL;
	free(del);
}

void deletePos(){
	if(head == NULL){
		printf("List is empty");
		return;
	}
	
	int pos;
	printf("Enter the position: ");
	scanf("%d", &pos);
	
	if(pos < 1){
		printf("Invalid position");
		return;
	}
	
	if(pos == 1){
		deleteBeg();
		return;
	}
	
	int i=1;
	struct Node* del = head;
	while(i<pos && del != NULL){
		del = del->next;
		i++;
	}
	
	if(del == NULL){
		printf("Position is out of bounds");
		return;
	}
	
	if(del->prev != NULL){
		del->prev->next = del->next;
	}
	if(del->next != NULL){
		del->next->prev = del->prev;
	}
	free(del);
}

void display(){
	if(head == NULL){
		printf("List is empty");
		return;
	}
	
	printf("list elements: ");
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main(void){
	int choice;
	while(1){
		printf("\n\n ------- MAIN MENU ------- \n");
		printf(" 1. Insert at Begining\n");
		printf(" 2. Insert at End\n");
		printf(" 3. Insert at any position\n");
		printf(" 4. Delete from Begining\n");
		printf(" 5. Delete from End\n");
		printf(" 6. Delete from any position\n");
		printf(" 7. Display List\n");
		printf(" 8. Exit\n");
		printf(" ------------------------- \n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				insertBeg();
				break;
			case 2:
				insertEnd();
				break;
			case 3:
				insertPos();
				break;
			case 4:
				deleteBeg();
				break;
			case 5:
				deleteEnd();
				break;
			case 6:
				deletePos();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Exiting ...\n");
				exit(0);
			default:
				printf("Invalid choice");
				continue;
		}
	}
	return 0;
}
