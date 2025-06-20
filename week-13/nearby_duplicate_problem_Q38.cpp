/*
.Given an array of integers of size n, design an algorithm and write a 
program to check whether this array contains duplicate within a small 
window of size k < n.
*/



#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool containsNearbyDuplicate(const vector<int>& arr, int k) {
    unordered_set<int> window;

    for (int i = 0; i < arr.size(); i++) {
        // If duplicate found in current window
        if (window.find(arr[i]) != window.end())
            return true;

        // Add current element to the window
        window.insert(arr[i]);

        // Maintain window size
        if (window.size() > k) {
            window.erase(arr[i - k]);
        }
    }

    return false;
}

int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter window size k: ";
    cin >> k;

    if (containsNearbyDuplicate(arr, k))
        cout << "Duplicates found within window of size " << k << ".\n";
    else
        cout << "No duplicates found within window of size " << k << ".\n";

    return 0;
}
