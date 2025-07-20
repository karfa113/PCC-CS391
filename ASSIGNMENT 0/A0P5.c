//Linear Search

#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p, n,z, pos;
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

    printf("Enter the element to be searched: ");
    scanf("%d", &z);
    for(int i=0; i<n; i++){
        if(p[i] == z){
            pos = i;
            break;
        }
    }

    printf("Element found at index: %d", pos);

    free(p);
    return 0;
}