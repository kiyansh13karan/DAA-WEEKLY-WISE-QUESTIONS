/*
Given a sequence of matrices, write an algorithm to find most efficient 
way to multiply these matrices together. To find the optimal solution, 
you need to find the order in which these matrices should be multiplied.
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to print the optimal parenthesis
void printParenthesis(int i, int j, vector<vector<int>>& bracket, char& name) {
    if (i == j) {
        cout << name++;
        return;
    }

    cout << "(";
    printParenthesis(i, bracket[i][j], bracket, name);
    printParenthesis(bracket[i][j] + 1, j, bracket, name);
    cout << ")";
}

// Function to compute the minimum multiplication cost
int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1; // number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<vector<int>> bracket(n, vector<int>(n, 0));

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << dp[0][n - 1] << endl;

    char name = 'A';
    cout << "Optimal Parenthesization: ";
    printParenthesis(0, n - 1, bracket, name);
    cout << endl;

    return dp[0][n - 1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter dimensions array (length " << n + 1 << "): ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainOrder(p);

    return 0;
}
