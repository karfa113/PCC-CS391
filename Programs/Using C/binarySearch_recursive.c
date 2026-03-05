#include<stdio.h>

int binary(int arr[], int low, int high, int target){
    int mid = (low+high)/2;

    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        return binary(arr, mid+1, high, target);
    }else{
        return binary(arr, low, mid-1, target);
    }
    return -1;
}

int main(void){
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter target element: ");
    scanf("%d", &target);

    int pos = binary(arr, 0, n-1, target);
    if(pos == -1){
        printf("Element not found");
    }else{
        printf("Element found at pos: %d", pos+1);
    }

    return 0;
}