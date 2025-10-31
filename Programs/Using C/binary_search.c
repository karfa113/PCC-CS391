#include<stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i=0; i<n-1; i++) {
        minIndex = i;
        for (j = i+1; j<n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int binarySearch(int arr[], int n, int target){
	int low = 0, high = n-1;
	while(low <= high){
		int mid = (low + high) / 2;
		
		if(arr[mid] == target)
			return mid;
		else if(arr[mid] < target)
			low = mid+1;
		else
			high = mid-1; 
	}
	return -1;
}

int main(void){
	int n;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	int arr[n];
	
	printf("Enter %d elements: \n", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	selectionSort(arr, n);
	
	printf("Sorted array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	int target;
	printf("Enter the element to be searched: ");
	scanf("%d", &target);
	int result = binarySearch(arr, n, target);
	if(result != -1)
		printf("Element found at position %d\n", result+1);
	else
		printf("Element not found\n");
		
	return 0;
}
