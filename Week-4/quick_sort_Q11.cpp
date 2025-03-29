/*
 Given an unsorted array of integers , design an algorithm and
 implement it using a program to sort an array of elements by partitioning
 the array into two sub arrays based on a pivot element such that one of
 the sub array holds values smaller than the pivot element while another
 subarray holds values greater than the pivot element. Pivot element
 should be selected randomly from the array.Your program should also
 find number of comparisons and swaps required for sorting the array.
*/



#include<iostream>
using namespace std ; 

int partition(int arr[] , int start , int end) {
    int pos = start ; 
    for(int i=start ; i<=end ; i++) {
        if(arr[i] <= arr[end]) {
            swap(arr[i] , arr[pos]) ;
            pos++ ;  
        }
    }
    return pos-1 ; 
}

void quicksort(int arr[] , int start , int end) {
    if(start >= end) {
        return ; 
    }
    // partition krenge 
    int p = partition(arr , start , end) ; 

    // left krenge 
    quicksort(arr , start , p-1) ; 
    // right krenge 
    quicksort(arr , p+1 , end) ; 
}

int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    int arr[1000] ; 
    cout<<"Enter the elements : "<<endl ;
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    quicksort(arr , 0 , n-1) ; 

    cout<<"Sorted array : "<<endl ; 
    for(int i=0 ; i<n ; i ++) {
        cout<<arr[i]<<" " ; 
    }
}