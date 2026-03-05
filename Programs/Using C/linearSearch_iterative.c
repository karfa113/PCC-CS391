#include<stdio.h>

void linear(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            printf("Element found at position: %d",i+1);
            return;
        }
    }
}

int main(void){
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int target;
    printf("Enter target element: ");
    scanf("%d", &target);

    linear(arr, n, target);
    return 0;
}