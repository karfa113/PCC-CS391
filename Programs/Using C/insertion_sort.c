#include<stdio.h>

void insertionSort(int arr[], int n){
	int temp, i, j;
	for(i=1; i<n; i++){
		temp = arr[i];
		j = i-1;
		while(temp < arr[j] && j >= 0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main(void){
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	
	printf("Enter %d elements: \n", n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	insertionSort(arr, n);
	
	printf("Sorted array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
