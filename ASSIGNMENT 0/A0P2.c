//Insert an element x at the position y

#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *p, n,x, pos;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    p = (int *)malloc((n+1) * sizeof(int));

    if (p == NULL){
        printf("Can't allocate memory right now");
        return 0;
    }

    printf("Enter elements into the array: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &p[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &x);
    printf("Enter the index: ");
    scanf("%d", &pos);

    for(int i=n; i>=pos+1; i--){
        p[i] = p[i-1];
    }

    p[pos] = x;

    printf("Updated array: \n");
    for(int i=0; i<=n; i++){
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}