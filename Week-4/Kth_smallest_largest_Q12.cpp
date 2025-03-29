/*
 Given an unsorted array of integers, design an algorithm and
 implement it using a program to find Kth smallest or largest element in
 the array. (Worst case Time Complexity = O(n))
*/


#include <iostream>
using namespace std;

// Function to partition the array using Lomuto partition scheme
int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // Choosing the last element as pivot
    int i = left; 

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);  // Place pivot at its correct position
    return i;  // Return pivot index
}

// QuickSelect function to find the K-th smallest element
int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k) {
            return arr[pivotIndex];  // Found the K-th smallest element
        } else if (pivotIndex > k) {
            return quickSelect(arr, left, pivotIndex - 1, k);  // Search in the left subarray
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k);  // Search in the right subarray
        }
    }
    return -1;  // Should never be reached
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[1000];  // Array with a max size of 1000
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of K: ";
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid value of K!" << endl;
        return 0;
    }

    // Finding K-th smallest element
    int kthSmallest = quickSelect(arr, 0, n - 1, k - 1);
    cout << "K-th smallest element: " << kthSmallest << endl;

    // Finding K-th largest element (Equivalent to finding (n-K+1)th smallest)
    int kthLargest = quickSelect(arr, 0, n - 1, n - k);
    cout << "K-th largest element: " << kthLargest << endl;

    return 0;
}