/*
Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.

Input:
- n (number of vertices)
- m (number of edges)
- m pairs of edges (u, v)

Output:
- Print n x n adjacency matrix
*/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int adj[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}