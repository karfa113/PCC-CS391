#include<stdio.h>

void hanoi(int n, char source, char auxillary, char destination){
    if(n==1){
        printf("Move disc 1 from %c to %c\n", source, destination);
        return;
    }

    hanoi(n-1, source, destination, auxillary);
    printf("Move disc %d from %c to %c\n",n, source, destination);
    hanoi(n-1, auxillary, source, destination);
}

int main(void){
    int n;
    printf("Enter number of disc: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'B', 'C');

    return 0;
}