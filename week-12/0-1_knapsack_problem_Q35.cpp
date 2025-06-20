/*
Given a knapsack of maximum capacity w. N items are provided, 
each having its own value and weight. Design an algorithm and 
implement it using a program to find the list of the selected items such 
that the final selected content has weight <= w and has maximum 
value. Here, you cannot break an item i.e. either pick the complete item
 or don't pick it. (0-1 property)
*/



#include <iostream>
#include <vector>
using namespace std;

void knapsack(int W, vector<int>& weight, vector<int>& value, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= N; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum value: " << dp[N][W] << endl;

    // Reconstruct the selected items
    int w = W;
    cout << "Selected items (0-indexed): ";
    for (int i = N; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << (i - 1) << " ";
            w -= weight[i - 1];
        }
    }
    cout << endl;
}

int main() {
    int N, W;
    cout << "Enter number of items: ";
    cin >> N;

    vector<int> weight(N), value(N);
    cout << "Enter weights of items:\n";
    for (int i = 0; i < N; i++)
        cin >> weight[i];

    cout << "Enter values of items:\n";
    for (int i = 0; i < N; i++)
        cin >> value[i];

    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    knapsack(W, weight, value, N);

    return 0;
}
