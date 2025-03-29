/*
 Given an already sorted array of positive integers, design an
 algorithm and implement it using a program to find whether given key
 element is present in the array or not. Also, find total number of
 comparisons for each input case.(Time Complexity = O(nlogn), where n
 is the size of input)
*/


#include<iostream>
using namespace std ; 

// binary search function 
int BinarySearch(int arr[] , int n , int key , int &comparison) {
    comparison = 0 ; 
    int start=0 , end=n-1 , mid ; 
    while(start<=end) {
        mid = (start + end)/2 ; 
        comparison++ ; 
        if(arr[mid]==key) {
            return mid ; 
        } else if(arr[mid]<key) {
            start = mid + 1 ; 
        } else {
            end = mid - 1 ; 
        }
    } 
    return -1 ; // element not found 
}


int main() {
    // initializing array dynamically 
    int arr[1000] ; 
    // initializing array size 
    int n ;
    cout<<"Enter the size of an array : " ; 
    cin>>n ;
    // taking array elements from the user 
    cout<<"Enter the elements : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }
    // taking key for finding
    int key ; 
    cout<<"Enter the key : " ; 
    cin>>key ; 

    cout<<endl ; 
    int comparison ; 
    int result = BinarySearch(arr , n , key , comparison) ; 

    if(result != -1) {
        cout<<"Element found at index : "<<result<<endl ; 
    } else {
        cout<<"Element not found in the array."<<endl ;
    }

    cout<<"Total comparisons made: "<<comparison<<endl ;

    return 0 ; 
}