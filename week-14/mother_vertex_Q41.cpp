/*
.Given a directed graph, write an algorithm and a program to find 
mother vertex in a graph. A mother vertex is a vertex v such that there 
exists a path from v to all other vertices of the graph.
*/



#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);  // Directed edge
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

    int findMotherVertex() {
        vector<bool> visited(V, false);
        int lastV = 0;

        // Step 1: Do a full DFS traversal and track last finished vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
                lastV = i;
            }
        }

        // Step 2: Check if last finished vertex is mother vertex
        fill(visited.begin(), visited.end(), false);
        DFSUtil(lastV, visited);

        for (bool v : visited) {
            if (!v)
                return -1;  // No mother vertex
        }

        return lastV;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int mother = g.findMotherVertex();
    if (mother != -1)
        cout << "Mother Vertex is: " << mother << endl;
    else
        cout << "No Mother Vertex exists in the graph.\n";

    return 0;
}
