/*
 Given a sorted array of positive integers containing few duplicate
 elements, design an algorithm and implement it using a program to find
 whether the given key element is present in the array or not. If present,
 then also find the number of copies of given key. (Time Complexity = O(log n))
*/


#include<iostream>
using namespace std ; 
// calculating first occurence of the element 
int firstoccu(int arr[] , int n , int key) {
    int start=0 , end=n-1 , mid , firstindex=-1 ; 
    while(start <= end) {
        mid = (start + end)/2 ; 
        if(arr[mid] == key) {
            firstindex = mid ; 
            end = mid - 1 ; 
        } else if(arr[mid] < key) {
            start = mid + 1 ; 
        } else {
            end = mid - 1 ; 
        }
    }
    return firstindex ; 
}

// calculating last occurence of the array
int lastoccu(int arr[] , int n , int key) {
    int start=0 , end=n-1 , mid , lastindex=-1 ; 
    while(start <= end) {
        mid = (start + end)/2 ; 
        if(arr[mid] == key) {
            lastindex = mid ; 
            start = mid + 1 ; 
        } else if(arr[mid] < key) {
            start = mid + 1 ; 
        } else {
            end = mid - 1 ;
        }
    }
    return lastindex ; 
}


int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 
    
    int arr[n] ; 
    cout<<"Enter the elements of array in sorted form : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }
    
    int key ; 
    cout<<"Enter the element for searching : " ; 
    cin>>key ; 

    int firstoccurence = firstoccu(arr , n , key) ; 
    int lastoccurence = lastoccu(arr , n , key) ; 

    if(firstoccurence == -1) {
        cout<<"Element "<<key<<" is not present in the array." ; 
    } else {
        int count = (lastoccurence - firstoccurence) + 1 ; 
        cout<<"Element "<<key<<" is present "<<count<<" times in the array." ;  
    }

    return 0 ;     
}