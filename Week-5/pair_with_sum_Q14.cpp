/*
 Given an unsorted array of integers, design an algorithm and implement it using a program to find
 whether two elements exist such that their sum is equal to the given key element. 
 (Time Complexity = O(n log n))
*/

#include<iostream>
#include<algorithm>
using namespace std ; 

bool pairwithsum(int arr[] , int n , int key) {
    sort(arr , arr+n) ; 

    int left = 0 ; 
    int right = n-1 ; 

    while(left < right) {
        int sum = arr[left] + arr[right] ; 
        if(sum == key) {
            return true ; 
        } else if(sum < key) {
            left++ ; 
        } else {
            right-- ; 
        }
    }
    return false ; 
}

int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 
    
    int arr[100] ; 
    cout<<"Enter the elements of an array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    int key ; 
    cout<<"Enter the key : " ; 
    cin>>key ; 

    int result = pairwithsum(arr , n , key) ;
    if(result == true) {
        cout<<"Pair found." ; 
    } else {
        cout<<"Pair not found." ; 
    }
    
    return 0 ; 
}