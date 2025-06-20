/*
Givenagraph, designanalgorithmand implement it usinga
 program to find if a graph is bipartite or not. (Hint: use BFS)
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<int> color;
bool isBipartite(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 0; // Start coloring with 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) { // If not colored
                color[neighbor] = 1 - color[node]; // Color with opposite color
                q.push(neighbor);
            } else if (color[neighbor] == color[node]) {
                return false; // Same color as current node, not bipartite
            }
        }
    }
    return true;
}
int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    graph.resize(V);
    color.resize(V, -1); // -1 means uncolored

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // Undirected graph
    }

    bool bipartite = true;
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) { // If not colored
            if (!isBipartite(i)) {
                bipartite = false;
                break;
            }
        }
    }

    if (bipartite)
        cout << "The graph is bipartite.\n";
    else
        cout << "The graph is not bipartite.\n";

    return 0;
}   



// Sample Input:
// Enter number of vertices and edges: 5 5
// Enter the edges (u v):
// 0 1
// 0 2
// 1 3
// 2 4
// 3 4
// Sample Output:
// The graph is bipartite.
