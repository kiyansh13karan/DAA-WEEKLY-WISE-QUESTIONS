/*
Givenagraph,Designanalgorithmand implement it usinga
 program to implement Floyd- Warshall all pair shortest path algorithm.
*/


#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // A large value representing infinity

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist = graph; // Create a distance matrix

    // Main Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of cities:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter number of cities: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (use " << INF << " for no direct road):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    floydWarshall(graph, V);

    return 0;
}
