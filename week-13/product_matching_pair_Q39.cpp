/*
Given an array of nonnegative integers, Design an algorithm and 
implement it using a program to find two pairs (a,b) and (c,d) such that 
a*b = c*d, where a, b, c and d are distinct elements of array
*/



#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool findEqualProductPairs(const vector<int>& arr) {
    unordered_map<int, pair<int, int>> productMap;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];

            if (productMap.find(prod) != productMap.end()) {
                pair<int, int> prev = productMap[prod];
                // Ensure all elements are distinct
                if (prev.first != i && prev.first != j &&
                    prev.second != i && prev.second != j) {
                    cout << "Pairs found:\n";
                    cout << "(" << arr[prev.first] << ", " << arr[prev.second] << ") and ("
                         << arr[i] << ", " << arr[j] << ")\n";
                    cout << "Product: " << prod << endl;
                    return true;
                }
            } else {
                productMap[prod] = {i, j}; // store index pair
            }
        }
    }

    cout << "No such pairs found.\n";
    return false;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    findEqualProductPairs(arr);

    return 0;
}
