 /*
 Givena (directed/undirected) graph, designanalgorithmand
 implement itusingaprogramtofindifapathexistsbetweentwogiven
 vertices or not. (Hint: use DFS)
 */

 #include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

bool dfs(int current, int destination) {
    if (current == destination) return true;
    visited[current] = true;

    for (int neighbor : graph[current]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, destination)) return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    graph.resize(V);
    visited.resize(V, false);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // remove this line if graph is directed
    }

    int source, destination;
    cout << "Enter source and destination vertices: ";
    cin >> source >> destination;

    if (dfs(source, destination))
        cout << "Path exists between " << source << " and " << destination << ".\n";
    else
        cout << "No path exists between " << source << " and " << destination << ".\n";

    return 0;
}

