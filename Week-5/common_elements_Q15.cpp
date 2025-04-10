#include <iostream>
using namespace std;

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;

    cout << "Common elements : ";
    bool found = false;

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            cout << arr1[i] << " " ;
            found = true ;
            i++ ;
            j++ ;
        }
        else if(arr1[i] < arr2[j]) {
            i++ ;
        }
        else {
            j++ ;
        }
    }

    if (!found)
        cout << "None" ;
    
    cout << endl ;
}

int main() {
    int m ; 
    cout<<"Enter the size of first array : " ; 
    cin>>m ; 
    
    int arr1[100] ; 
    cout<<"Enter the elements of first array : "<<endl ; 
    for(int i=0 ; i<m ; i++) {
        cin>>arr1[i] ; 
    }

    int n ; 
    cout<<"Enter the size of second array : " ; 
    cin>>n ; 
    
    int arr2[100] ; 
    cout<<"Enter the elements of second array : "<<endl ; 
    for(int j=0 ; j<n ; j++) {
        cin>>arr2[j] ; 
    }


    findCommonElements(arr1 , m , arr2 , n);

    return 0 ;
}
