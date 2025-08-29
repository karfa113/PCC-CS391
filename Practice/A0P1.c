//Dynamically allocate memory for a array and print it

#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p,n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));

    if(p == NULL){
        printf("Can't allocate space right now");
        return 0;
    }

    printf("Enter elements into the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    printf("Entered array elements are: \n");
    for(int i=0; i<n; i++){
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}