/*
 Given an array of non negative integers,design an algorithm and
 a program to count the number of pairs of integers such that their
 difference is equal to a given key, K.
*/


#include<iostream>
using namespace std ; 

int countpairwithdifference(int arr[] , int n , int target) {
    int count = 0 ; 
    for(int i=0 ; i<n ; i++) {
        for(int j=i+1 ; j<n ; j++) {
            if(arr[i]-arr[j]==target || arr[j]-arr[i]==target) {
                count++ ; 
            }
        }
    }
    return count ; 
}

int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    int arr[n] ; 
    cout<<"Enter the elements of an array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    int target ; 
    cout<<"Enter the difference target : " ; 
    cin>>target ; 

    int result = countpairwithdifference(arr , n , target) ;
    cout << "Number of pairs with difference " << target << ": " << result << endl;

    return 0 ;; 
}