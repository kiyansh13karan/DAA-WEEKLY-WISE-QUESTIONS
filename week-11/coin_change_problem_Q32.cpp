/*
.Given a set of available types of coins. Let suppose you have infinite 
supply of each type of coin. For a given value N, you have to Design an
 algorithm and implement it using a program to find number of ways in 
which these coins can be added to make sum value equals to N
*/



#include <iostream>
#include <vector>
using namespace std;

int countWaysToMakeChange(int N, vector<int>& coins) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1; // Base case: one way to make sum 0

    for (int coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[N];
}

int main() {
    int n, sum;
    cout << "Enter number of coin types: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the total sum (N): ";
    cin >> sum;

    int ways = countWaysToMakeChange(sum, coins);
    cout << "Number of ways to make sum " << sum << ": " << ways << endl;

    return 0;
}
