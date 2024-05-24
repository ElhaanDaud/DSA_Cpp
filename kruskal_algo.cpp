#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent(int v, vector<int>& parent) {
    if (parent[v] == v)
        return v;
    return findParent(parent[v], parent);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

void Kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(V);
    vector<int> rank(V, 0);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    vector<Edge> mst;

    for (Edge e : edges) {
        int u = findParent(e.src, parent);
        int v = findParent(e.dest, parent);

        if (u != v) {
            mst.push_back(e);
            unionSet(u, v, parent, rank);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge e : mst) {
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    }
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    Kruskal(V, edges);

    return 0;
}
