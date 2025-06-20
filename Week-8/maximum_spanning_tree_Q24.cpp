/*
Assumethatsameroadconstructionproject isgiventoanother
 person.Theamounthewillearnfromthisproject isdirectlyproportional
 to thebudget of theproject.Thisperson isgreedy, sohedecided to 
 maximize thebudget byconstructing those roadswhohavehighest
 constructioncost.Designanalgorithmandimplement itusingaprogram
 to find the maximum budget required for the project.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

// Sort edges in descending order for maximum spanning tree
bool compare(Edge a, Edge b) {
    return a.weight > b.weight;
}

// Find with path compression
int findParent(int node, vector<int>& parent) {
    if (parent[node] != node)
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

// Union by rank
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

void maximumSpanningTree(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    vector<Edge> result;

    for (auto edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            result.push_back(edge);
            totalCost += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
        }
    }

    cout << "Roads constructed (city1 - city2) with cost:\n";
    for (auto e : result)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    cout << "Maximum total budget (maximum cost to connect all cities): " << totalCost << endl;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<Edge> edges;
    cout << "Enter the cost matrix (0 if no road between cities):\n";
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cost;
            cin >> cost;
            if (cost != 0)
                edges.push_back({i, j, cost});
        }
    }

    maximumSpanningTree(edges, n);

    return 0;
}
