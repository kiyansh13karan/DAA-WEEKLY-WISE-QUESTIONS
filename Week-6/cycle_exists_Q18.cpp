/*
 Givenadirectedgraph, designanalgorithmand implement it
 using a program to find whether cycle exists in the graph or not.
*/


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited, recStack;

bool dfs(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor)) return true;
        } else if (recStack[neighbor]) {
            return true; // Back edge found -> cycle exists
        }
    }

    recStack[node] = false; // Remove node from recursion stack
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    graph.resize(V);
    visited.resize(V, false);
    recStack.resize(V, false);

    cout << "Enter the directed edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); // Directed edge
    }

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i)) {
                cout << "Yes Cycle Exists\n";
                return 0;
            }
        }
    }

    cout << "No Cycle Exists\n";
    return 0;
}
