#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int arr[], int n){
	for(int i=0; i < n-1; i++){
		for(int j=0; j < n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

int main(){
	int arr[] = {4,5,8,7,4,6,3,2};
	int n = sizeof(arr)/sizeof(arr[0]);

	BubbleSort(arr, n);

	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
}