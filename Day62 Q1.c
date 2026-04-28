/*
Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

Input:
- n (number of vertices)
- m (number of edges)
- m pairs of edges (u, v)

Output:
- Print adjacency list for each vertex
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}