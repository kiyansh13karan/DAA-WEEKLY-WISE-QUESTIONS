/*
Given two sequences, Design an algorithm and implement it using a 
program to find the length of longest subsequence present in both of 
them. A subsequence is a sequence that appears in the same relative 
order, but not necessarily contiguous.
*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcsLength(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D DP table initialized with 0
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];  // Final answer
}

int main() {
    string X, Y;

    cout << "Enter the first sequence: ";
    cin >> X;

    cout << "Enter the second sequence: ";
    cin >> Y;

    int length = lcsLength(X, Y);

    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}
