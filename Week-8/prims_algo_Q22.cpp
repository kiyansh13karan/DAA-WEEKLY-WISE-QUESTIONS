/*
Assume that a project of road construction to connect some cities
 is given to your friend. Map of these cities and roads which will connect
 them (after construction)is provided to him in the form of a graph. Certain
 amount of rupees is associated with construction of each road. Your
 friend has to calculate the minimum budget required for this project. The
 budget should be designed in such away that the cost of connecting the
 cities should be minimum and number of roads required to connect all
 the cities should be minimum(if there are N cities then only N-1 roads
 need to be constructed). He asks you for help. Now, you have to help
 your friend by designing an algorithm which will find minimum cost
 required to connect these cities. (use Prim's algorithm)
*/


#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Function to find the vertex with the minimum key value
int minKey(vector<int>& key, vector<bool>& inMST, int n) {
    int min = INF, min_index;

    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v], min_index = v;
        }
    }

    return min_index;
}

// Function to construct and print MST using Prim's algorithm
void primMST(vector<vector<int>>& graph, int n) {
    vector<int> parent(n);   // Array to store constructed MST
    vector<int> key(n, INF); // Key values to pick minimum weight edge
    vector<bool> inMST(n, false); // To represent set of vertices included in MST

    key[0] = 0;      // Include first vertex in MST
    parent[0] = -1;  // First node is always root of MST

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, inMST, n);
        inMST[u] = true;

        for (int v = 0; v < n; v++) {
            // Update key only if graph[u][v] is smaller and v is not in MST
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    int totalCost = 0;
    cout << "Roads constructed (city1 - city2) with cost:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum total cost to connect all cities: " << totalCost << endl;
}

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the cost matrix (0 if no road between cities):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    primMST(graph, n);

    return 0;
}

