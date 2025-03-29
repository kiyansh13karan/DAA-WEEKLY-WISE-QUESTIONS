/*
 Given an unsorted array of integers , design an algorithm and a
 program to sort the array using insertion sort. Your program should be
 able to find number of comparisons and shifts (shifts-total number of
 times the array elements are shifted from their place) required for sorting
 the array
*/


// insertion sort 
#include<iostream>
using namespace std ; 
int main() {
    // taking the size of the array
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    int arr[1000] ;
    // scanning the numbers of the array 
    cout<<"Enter the elements of an array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    } 

    // insertion sort algorithm  
    int comparison = 0 ; 
    int shifts = 0 ; 
    for(int i=1 ; i<n ; i++) { 
        for(int j=i ; j>0 ; j--) {
            comparison++ ; 
            if(arr[j] < arr[j-1]) { 
                swap(arr[j] , arr[j-1]) ;
                shifts++ ;   
            } else {
                break ; 
            }
        }
    }

    // print the sorted array
    cout<<"Sorted array is : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cout<<arr[i]<<" " ; 
    }
    cout<<endl ; 
    cout<<"Number of comparison : "<<comparison<<endl ; 
    cout<<"Number of shifts : "<<shifts<<endl ; 
    return 0 ; 
}