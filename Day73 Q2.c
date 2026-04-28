/*
Problem Statement:
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added.
The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes.
If there are multiple answers, return the answer that occurs last in the input.
*/

#include <stdlib.h>

int parent[1001];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    for (int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            result[0] = u;
            result[1] = v;
            *returnSize = 2;
            return result;
        }

        parent[pu] = pv;
    }

    *returnSize = 0;
    return NULL;
}