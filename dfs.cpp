//Write a program to show the working of depth first search

#include <iostream>
#include <vector>
using namespace std;

void DFSUtil(int v, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[v] = true;
    cout << v << " ";

    for (int i : adj[v]) {
        if (!visited[i])
            DFSUtil(i, visited, adj);
    }
}

void DFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            DFSUtil(i, visited, adj);
    }
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V);

    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "Depth First Traversal: ";
    DFS(V, adj);

    return 0;
}
