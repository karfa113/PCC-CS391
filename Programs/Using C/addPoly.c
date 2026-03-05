#include<stdio.h>
#include<stdlib.h>

struct Node{
    int coef;
    int exp;
    struct Node* next;
};

struct Node* createNew(int coef, int exp){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode != NULL){
        newNode->coef = coef;
        newNode->exp = exp;
        newNode->next = NULL;
    }
    return newNode;
}

struct Node* insert(struct Node* head, int coef, int exp){
    struct Node* newNode = createNew(coef, exp);

    if(head == NULL || head->exp < exp){
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while(temp->next != NULL && temp->next->exp > exp){
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* add(struct Node* poly1, struct Node* poly2){
    struct Node* result = NULL;

    if(poly1->exp == poly2->exp){
        result = insert(result, poly1->coef + poly2->coef, poly1->exp);
        poly1 = poly1->next;
        poly2 = poly2->next;
    }else if(poly1->exp > poly2->exp){
        result = insert(result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }else{
        result = insert(result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    while(poly1 != NULL){
        result = insert(result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while(poly2 != NULL){
        result = insert(result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

void display(struct Node* head){
    while(head != NULL){
        printf("%dx^%d", head->coef, head->exp);
        if(head->next != NULL){
            printf(" + ");
        }
        head = head->next;
    }
}

int main(void){
    struct Node* poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coef=0, exp=0;

    printf("Enter number of terms in first polymomial: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coef, &exp);
        poly1 = insert(poly1, coef, exp);
    }

    printf("Enter number of terms in second polymomial: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter coefficient and exponent: ");
        scanf("%d%d", &coef, &exp);
        poly2 = insert(poly2, coef, exp);
    }

    result = add(poly1, poly2);

    printf("Resultant polynomial: \n");
    display(result);
    return 0;
}