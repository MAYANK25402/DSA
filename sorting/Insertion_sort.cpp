#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void insertion(int arr[], int size){

    int i, j, temp;
    for (i = 1; i < size; i++){
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i]<<" ";
    cout << endl;
}

int main(){
    // freopen("../input.txt", "r", stdin);  
    freopen("../output.txt", "w", stdout);
    
    int arr[] = {100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // start time
    auto start = high_resolution_clock::now();

    insertion(arr, n);

    // end time
    auto stop = high_resolution_clock::now();

    printArray(arr, n);

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;

    return 0;
}
