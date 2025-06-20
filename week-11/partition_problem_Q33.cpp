/*
Given a set of elements, you have to partition the set into two 
subsets such that the sum of elements in both subsets is same. Design 
an algorithm and implement it using a program to solve this problem.
*/



#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& arr) {
    int total = 0;
    for (int num : arr)
        total += num;

    // If total is odd, we cannot split into two equal subsets
    if (total % 2 != 0)
        return false;

    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : arr) {
        for (int i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }

    return dp[target];
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (canPartition(arr))
        cout << "The set can be partitioned into two subsets with equal sum.\n";
    else
        cout << "The set CANNOT be partitioned into two subsets with equal sum.\n";

    return 0;
}
