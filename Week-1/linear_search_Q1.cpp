/*
 Given an array of non negative integers, design a linear algorithm
 and implement it using a program to find whether given key element is
 present in the array or not. Also, find total number of comparisons for
 each input case. (Time Complexity = O(n), where n is the size of input
*/


#include<iostream>
using namespace std ; 

// funtion to perform linear search 
int linear_search(int arr[] , int n , int k , int &comparison) {
    comparison = 0 ; 
    for(int i=0 ; i<n ; i++) {
        comparison++ ; 
        if(arr[i] == k) {
            return i ; // element found and return its index 
        }
    }
    return -1 ; // element not found 
}

int main() {
    // initializing the size of an array 
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    // initializing array 
    int arr[n] ; 
    //taking elements of an array from the user 
    cout<<"Enter the elements of an array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    // taking the element for searching from the user
    int k ; 
    cout<<"Enter the number for searching : " ; 
    cin>>k ; 

    int comparison ; 
    int result = linear_search(arr , n , k , comparison) ;
    
    if(result != -1) {
        cout<<"Element found at index "<<result<<endl ; 
    } else {
        cout<<"Element"<<k<<" <not found in array." ; 
    }

    cout<<"Number of comparisons : "<<comparison<<endl ; 

    return 0 ; 
}