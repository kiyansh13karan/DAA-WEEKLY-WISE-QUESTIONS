/*
 Given a sorted array of positive integers , design an algorithm and
 implement it using a program to find three indices i , j ,k such that arr[i] + arr[j] = arr[k]
*/



#include<iostream>
using namespace std ; 

void triplet(int arr[] , int n) {
    bool found = false ; 
    for(int k=2 ; k<n ; k++) {
        int i=0 , j=k-1 ; 

        while(i < j) {
            int sum = arr[i] + arr[j] ; 

            if(sum == arr[k]) {
                cout<<"Indicies found : ("<<i<<" , "<<j<<" , "<<k<<")\n" ; 
                found = true ; 
                break ; 
            } else if(sum < arr[k]) {
                i++ ; // increase sum by moving left pointer right 
            } else {
                j-- ; // decrease sum by moving right pointer left 
            }
        }
    }
    if(!found) {
        cout<<"No such indicies found!" ; 
    }
}

int main() {
    int n ; 
    cout<<"Enter the size of an array : " ; 
    cin>>n ; 

    int arr[n] ; 
    cout<<"Enter the elements of an sorted array : "<<endl ; 
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ; 
    }

    triplet(arr , n) ; 

    return 0 ; 
}