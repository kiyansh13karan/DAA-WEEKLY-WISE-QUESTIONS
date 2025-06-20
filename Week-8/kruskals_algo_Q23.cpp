/*
 Implement the previous problem using Kruskal's algorithm
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Compare function to sort edges by weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Find function using path compression
int findParent(int node, vector<int>& parent) {
    if (parent[node] != node)
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

// Union function to join two subsets
void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's algorithm
void kruskalMST(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    // Initially each node is its own parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    vector<Edge> result;

    for (auto edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (findParent(u, parent) != findParent(v, parent)) {
            result.push_back(edge);
            totalCost += edge.weight;
            unionSets(u, v, parent, rank);
        }
    }

    cout << "Roads constructed (city1 - city2) with cost:\n";
    for (auto e : result)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    cout << "Minimum total cost to connect all cities: " << totalCost << endl;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<Edge> edges;

    cout << "Enter the cost matrix (0 if no road between cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // avoid duplicates
            int cost;
            cin >> cost;
            if (cost != 0) {
                edges.push_back({i, j, cost});
            }
        }
    }

    kruskalMST(edges, n);

    return 0;
}
