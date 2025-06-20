/*
 Given a directed graph with two vertices(source and destination).
 Design an algorithm and implement it using a program to find the weight
 of the shortest path from source to destination with exactly k edges on
 the path.
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int shortestPathWithKEdges(vector<vector<int>>& graph, int u, int v, int k, vector<vector<vector<int>>>& dp) {
    if (k == 0 && u == v) return 0;
    if (k == 0) return INF;

    if (dp[u][v][k] != -1) return dp[u][v][k];

    int res = INF;
    int V = graph.size();

    for (int i = 0; i < V; i++) {
        if (graph[u][i] != 0) {
            int subPath = shortestPathWithKEdges(graph, i, v, k - 1, dp);
            if (subPath != INF)
                res = min(res, graph[u][i] + subPath);
        }
    }

    return dp[u][v][k] = res;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src, dest, k;
    cin >> src >> dest >> k;

    vector<vector<vector<int>>> dp(V, vector<vector<int>>(V, vector<int>(k + 1, -1)));

    int result = shortestPathWithKEdges(graph, src, dest, k, dp);

    if (result == INF)
        cout << "no path of length k is available\n";
    else
        cout << "Shortest path weight with " << k << " edges: " << result << endl;

    return 0;
}
