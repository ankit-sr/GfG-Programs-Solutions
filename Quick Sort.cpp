#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i=low, j=high;
	while(i<j){
		do{
			i++;
		}while(arr[i]<pivot);
		
		do{
			j--;
		}while(arr[j]>pivot);
		
		if(i<j){
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[low], arr[j]);
	return j;
}

void quick_sort(int arr[], int low, int high){
	if(low<high){
		int p = partition(arr, low, high);
		quick_sort(arr,low,p);
		quick_sort(arr,p+1,high);
	}
}

int main(){
	int arr[] = {10,16,8,15,6,2,19,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	quick_sort(arr, 0, size);
	
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
