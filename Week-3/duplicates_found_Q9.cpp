/*
 Given an unsorted array of positive integers , design an algorithm
 and implement it using a program to find whether there are any duplicate
 elements in the array or not. (usesorting) (Time Complexity = O(nlog n))
*/



// to check whether there is duplicate element present or not using quick sort 

#include<iostream>
using namespace std ; 

int partition(int arr[] , int start , int end) {
    int pos = start ; 
    for(int i=start ; i<=end ; i++) {
        if(arr[i] <= arr[end]) {
            int temp = arr[i] ;
            arr[i] = arr[pos] ; 
            arr[pos] = temp ;  
            pos++ ; 
        }
    }
    return pos-1 ; 
}

void quicksort(int arr[] , int start , int end) {
    if(start >= end) {
        return ; 
    }
    int p = partition(arr , start , end) ; 
    quicksort(arr , start , p-1) ; 
    quicksort(arr , p+1 , end) ; 
}

bool duplicates(int arr[], int n) {
    
    quicksort(arr, 0, n - 1) ;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            return true; 
        }
    }
    return false ; 
}

int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    int arr[n] ; 
    
    cout<<"Enter the elements of an array : " ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    int result = duplicates(arr , n) ; 
    if(result == true) {
        cout<<"Duplicates element found." ; 
    } else {
        cout<<"Duplicates element not found." ; 
    }
     
}