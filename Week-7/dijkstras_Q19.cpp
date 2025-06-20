/*
After end term examination, Akshay wants to party with his
 friends.All his friends are living as paying guest and it has been decided
 to first gather at Akshay’s house and then move towards party location.
 The problem is that no one knows the exact address of his house in the
 city. Akshay as a computer science wizard knows how to apply his theory
 subjects in his real life and came up with an amazing idea to help his
 friends. He draws a graph by looking into location of his house and his
 friends’ location(as a node in the graph) on a map. He wishes to find out
 shortest distance and path covering that distance from each of his
 friend’s location to his house and then whatsapp them this path so that
 they can reach his house in minimum time. Akshay has developed the
 program that implements Dijkstra’s algorithm but not sure about
 correctness of results. Can you also implement the same algorithm and
 verify the correctness of Akshay’s results? (Hint:Print shortest path and
  distance from friends’ location to Akshay’s house)
*/



#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii; // (distance, vertex)

void dijkstra(int V, vector<vector<pii>>& adj, int source, vector<int>& dist, vector<int>& parent) {
    dist.assign(V, INT_MAX);
    parent.assign(V, -1);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}

int main() {
    int V, E;
    cout << "Enter number of nodes and edges: ";
    cin >> V >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter edges in the format: source destination weight\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        // Uncomment the line below if the graph is undirected
        // adj[v].emplace_back(u, w);
    }

    int source, target;
    cout << "Enter friend's location (source node): ";
    cin >> source;
    cout << "Enter Akshay's house (target node): ";
    cin >> target;

    vector<int> dist, parent;
    dijkstra(V, adj, source, dist, parent);

    if (dist[target] == INT_MAX) {
        cout << "No path exists from friend's location to Akshay's house.\n";
    } else {
        cout << "Shortest distance: " << dist[target] << "\n";
        cout << "Path: ";
        printPath(target, parent);
        cout << "\n";
    }

    return 0;
}
