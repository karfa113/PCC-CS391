//Remove the element from position s of the array

#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p, n, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));

    if (p == NULL){
        printf("Can't allocate memory right now");
        return 0;
    }

    printf("Enter elements into the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    printf("Enter the index to be removed: ");
    scanf("%d", &pos);

    for(int i=pos; i<n-1; i++){
        p[i] = p[i+1]; 
    }

    printf("Updated array: \n");
    for (int i=0; i<n-1; i++){
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}