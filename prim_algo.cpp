//Write a program to find minimum spanning tree using prim's algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <climits> // for INT_MAX
using namespace std;

typedef pair<int, int> pii;

void Prim(int V, vector<vector<pii>>& adj) {
    // Priority queue to select the edge with the smallest weight
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    // Vector to store the minimum weight to connect to each vertex
    vector<int> key(V, INT_MAX);
    // Vector to store the parent of each vertex in the MST
    vector<int> parent(V, -1);
    // Vector to keep track of vertices included in the MST
    vector<bool> inMST(V, false);

    // Start from the first vertex (0)
    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue; // If already in MST, skip
        inMST[u] = true;

        for (auto& [v, weight] : adj[u]) {
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    // Print the edges in the MST
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " -- " << i << " with weight " << key[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pii>> adj(V);

    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    Prim(V, adj);

    return 0;
}
