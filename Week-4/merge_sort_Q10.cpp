/*
 Given an unsorted array of integers , design an algorithm and
 implement it using a program to sort an array of elements by dividing the
 array into two sub arrays and combining these sub arrays after sorting
 each one of them. Your program should also find number of comparisons
 and inversions during sorting the array.
*/



#include <iostream>
#include <vector>
using namespace std;

int comparisons = 0 ; 
int inversions = 0 ;  

void merge(int arr[] , int start , int mid , int end) {
    vector<int> temp(end - start + 1) ;
    int left = start ;
    int right = mid + 1 ;
    int index = 0 ;

    while (left <= mid && right <= end) {
        comparisons++ ; 
        if (arr[left] <= arr[right]) {
            temp[index] = arr[left] ;
            index++ ; 
            left++ ; 
        } else {
            temp[index] = arr[right] ;
            index++ ;
            right++ ; 
            inversions = inversions + (mid - left + 1) ; 
        }
    }

    while (left <= mid) {
        temp[index] = arr[left] ;
        index++ ; 
        left++ ; 
    }
    while (right <= end) {
        temp[index] = arr[right] ;
        index++ ; 
        right++ ; 
    }

    for (int i = 0 ; i < temp.size() ; i++) {
        arr[start + i] = temp[i] ;
    }
}

void mergesort(int arr[] , int start , int end) {
    if (start >= end) {
        return ;
    }
    int mid = start+(end-start) / 2 ;

    mergesort(arr , start , mid) ;
    mergesort(arr , mid+1 , end) ;
    merge(arr , start , mid , end) ;
}

int main() {
    int n ;
    cout<<"Enter the size of the array: " ;
    cin>>n ;

    int arr[1000] ;
    cout<<"Enter the elements of the array: "<<endl;
    for(int i=0 ; i<n ; i++) {
        cin>>arr[i] ;
    }

    mergesort(arr , 0 , n-1) ;

    cout<<"Sorted array is : "<<endl ;
    for(int i = 0; i < n; i++) {
        cout<<arr[i] << " " ;
    }
    cout<<endl ; 

    cout << "Number of comparisons: " << comparisons << endl ;
    cout << "Number of inversions: " << inversions << endl ;

    return 0 ;
}