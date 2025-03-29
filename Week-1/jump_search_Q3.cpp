/*
 Given an already sorted array of positive integers, design an
 algorithm and implement it using a program to find whether a given key
 element is present in the sorted array or not. For an array arr[n], search
 at the indexes arr[0] , arr[2] , arr[4] , ... , arr[2k] and soon. Once the interval
 (arr[2k] < key<arr[2k+1] ) is found , perform a linear search operation from the
 index 2k to find the element key. (Complexity <O(n) , where n is the
 number of elements need to be scanned for searching): Jump Search
*/



#include<iostream>
#include<cmath>
using namespace std ; 

// jump search function 
int jump_search(int arr[] , int n , int k) {
    int step = sqrt(n) ; 
    int prev = 0 ; 
    
    // jumping 
    while(arr[min(step , n) -1] < k) {
        prev = step ; 
        step = step + sqrt(n) ; 
        if(prev >= n) {
            return -1 ; // element found 
        }
    }

    // performing linear search int the identified block 
    for(int i=prev ; i<min(step , n) ; i++) {
        if(arr[i] == k) {
            return i ; // element found 
        }
    }
    return -1 ; // element not found 
}

int main() {
    // initializing size 
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    // initialzing array
    int arr[n] ; 
    // taking elements of array from user 
    cout<<"Enter the elements of an array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }
    // taking element from the user to search 
    int k ; 
    cout<<"Enter the element to search : " ; 
    cin>>k ; 

    int result = jump_search(arr , n , k) ; 

    if(result != -1) {
        cout<<"Element found at index : "<<result<<endl ; 
    } else {
        cout<<"Element not found at array." ; 
    }
}