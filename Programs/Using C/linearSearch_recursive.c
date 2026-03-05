#include<stdio.h>

int linear(int arr[], int n, int target, int index){
    if(index >= n){
        return -1;
    }

    if(arr[index] == target){
        return index+1;
    }

    return linear(arr, n , target, index+1);
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

    int pos = linear(arr, n, target, 0);
    if(pos == -1){
        printf("Element not found");
    }else{
        printf("Element found at pos: %d", pos);
    }
    return 0;
}