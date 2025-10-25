#include<stdio.h>

void bubbleSort(int arr[], int n){
	int temp, flag = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				flag = 1;
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if(flag == 0)
			return;
	}
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
	
	bubbleSort(arr, n);
	
	printf("Sorted Array: ");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
