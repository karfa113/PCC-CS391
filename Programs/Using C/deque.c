#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int deque[MAX];
int left = -1;
int right = -1;

void insert_left(){
	int value;
	printf("Enter value to insert: ");
	scanf("%d", &value);
	if((left == -1 && right == MAX - 1) ||(left == right + 1)){
		printf("Overflow \n");
		return;
	}
	
	if(left == -1){
		left = right = 0;
	}else{
		if(left == 0){
			left = MAX - 1;
		}else{
			left = left - 1;
		}
	}
	deque[left] = value;
}

void insert_right(){
	int value;
	printf("Enter value to insert: ");
	scanf("%d", &value);
	
	if((left == -1 && right == MAX - 1) ||(left == right + 1)){
		printf("Overflow \n");
		return;
	}
	
	if(left == -1){
		left = right = 0;
	}else{
		if(right == MAX - 1){
			right = 0;
		}else{
			right = right + 1;
		}
	}
	deque[right] = value;
}

void delete_right(){
	if(left == -1){
		printf("Underflow \n");
		return;
	}
	
	printf("Deleted element: %d\n", deque[right]);
	if(left == right){
		left = right = -1;
	}else{
		if(right == 0){
			right = MAX - 1;
		}else{
			right = right - 1;
		}
	}
}

void delete_left(){
	if(left == -1){
		printf("Underflow \n");
		return;
	}
	
	printf("Deleted element: %d\n", deque[right]);
	if(left == right){
		left = right = -1;
	}else{
		if(left == MAX - 1){
			left = 0;
		}else{
			left = left + 1;
		}
	}
}

void display(){
	int front = left, rear = right;
	if(rear == -1){
		printf("Queue is empty \n");
		return;
	}
	
	printf("\nQueue elements are: ");
	if(front <= rear){
		while(front <= rear){
			printf("%d ", deque[front]);
			front++;
		}
	}else{
		while(front <= MAX - 1){
			printf("%d ", deque[front]);
			front++;
		}
		front = 0;
		while(front <= rear){
			printf("%d ", deque[front]);
			front++;
		}
	}
	printf("\n");
}

void input_restricted(){
	int option;
	while(1){
		printf("\n\n ---- Input Restricted Deque ---- \n");
		printf("1. Insert right \n");
		printf("2. Delete left \n");
		printf("3. Delete right \n");
		printf("4. Display \n");
		printf("5. Quit \n");
		printf(" -------------------------------- \n");
		printf("Enter your choice: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_right();
				break;
			case 2:
				delete_left();
				break;
			case 3:
				delete_right();
				break;
			case 4:
				display();
				break;
			case 5:
				return;
			default:
				printf("Invalid choice");
				continue;
		}
	}
}

void output_restricted(){
	int option;
	while(1){
		printf("\n\n ---- Output Restricted Deque ---- \n");
		printf("1. Insert left \n");
		printf("2. Insert right \n");
		printf("3. Delete left \n");
		printf("4. Display \n");
		printf("5. Quit \n");
		printf(" ---------------------------------- \n");
		printf("Enter your choice: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				insert_left();
				break;
			case 2:
				delete_right();
				break;
			case 3:
				delete_left();
				break;
			case 4:
				display();
				break;
			case 5:
				return;
			default:
				printf("Invalid choice");
				continue;
		}
	}
}

int main(void){
	int choice;
	printf("\n\n ----- MAIN MENU ----- \n");
	printf("1. Input Restricted Deque \n");
	printf("2. Output Restricted Deque \n");
	printf("3. Exit \n");
	printf(" --------------------- \n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			input_restricted();
			break;
		case 2:
			output_restricted();
			break;
		case 3:
			exit(0);
		default:
			printf("Invalid choice \n");
	}
	return 0;
}
