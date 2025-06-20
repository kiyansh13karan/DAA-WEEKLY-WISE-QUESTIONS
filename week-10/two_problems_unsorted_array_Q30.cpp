/*
 Givenanunsortedarrayof elements, designanalgorithmand
 implement itusingaprogramtofindwhethermajorityelementexistsor
 not.Alsofindmedianof thearray.Amajorityelement isanelement that
 appears more than n/2 times, where n is the size of array.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find majority element using Boyer-Moore algorithm
int findMajorityCandidate(const vector<int>& arr) {
    int count = 0, candidate = -1;

    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        }
        else if (num == candidate) {
            count++;
        }
        else {
            count--;
        }
    }

    // Verify candidate
    count = 0;
    for (int num : arr) {
        if (num == candidate) count++;
    }

    if (count > arr.size() / 2)
        return candidate;
    else
        return -1; // No majority element
}

// Function to find median
double findMedian(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    if (n % 2 == 1) {
        return arr[n / 2];
    } else {
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Majority element
    int majority = findMajorityCandidate(arr);
    if (majority != -1)
        cout << "Majority element exists: " << majority << endl;
    else
        cout << "No majority element exists.\n";

    // Median
    double median = findMedian(arr);
    cout << "Median of the array: " << median << endl;

    return 0;
}
