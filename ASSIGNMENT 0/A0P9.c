#include<stdio.h>
#include<string.h>
#define SIZE 100

int main(void){
    char string1[SIZE];
    char string2[SIZE];
    int o1 = 0, c1 = 0, o2 = 0, c2 =0;

    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);

    for(int i=0; string1[i] != '\0'; i++){
        if(string1[i] == '(') o1++;
        if(string1[i] == ')') c1++;
    }

    for(int i=0; string2[i] != '\0'; i++){
        if(string2[i] == '(') o2++;
        if(string2[i] == ')') c2++;
    }

    if(o1 == o2 && c1 == c2){
        printf("Brackets are equal");
    }else{
        printf("Brackets are not equal");
    }

    return 0;
}