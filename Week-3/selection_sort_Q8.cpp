/*
 Given an unsorted array of integers , design an algorithm and
 implement a program to sort this array using selection sort.Your program
 should also find number of comparisons and number of swaps required.
*/


#include <iostream>
using namespace std;

int main() {
    // Taking the size of the array
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    int arr[1000]; // Declaring array

    // Scanning the numbers of the array
    cout << "Enter the elements of an array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Selection Sort algorithm
    int comparisons = 0, swaps = 0; // Counters for comparisons and swaps

    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++; // Increment comparison counter
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        // Swap only if necessary
        if (index != i) {
            swap(arr[i], arr[index]);
            swaps++; // Increment swap counter
        }
    }

    // Print the sorted array
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print the number of comparisons and swaps
    cout << "Number of comparisons: " << comparisons << endl ;
    cout << "Number of swaps: " << swaps << endl ;

    return 0;
}