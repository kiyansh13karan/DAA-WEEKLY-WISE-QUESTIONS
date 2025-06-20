/*
 Design an algorithm and implement it using a program to solve
 previous question's problem using Bellman-Ford's shortest path
 algorithm.
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void printPath(int v, vector<int>& parent) {
    if (parent[v] == -1) {
        cout << v << " ";
        return;
    }
    printPath(parent[v], parent);
    cout << v << " ";
}

int main() {
    int V;
    cin >> V;

    vector<Edge> edges;
    int weight;

    // Read adjacency matrix and build edge list
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> weight;
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }

    int source;
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;

    // Bellman-Ford algorithm
    for (int i = 0; i < V - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    // Output
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << " : No path" << endl;
        } else {
            printPath(i, parent);
            cout << ": " << dist[i] << endl;
        }
    }

    return 0;
}
