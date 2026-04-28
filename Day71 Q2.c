/*
Problem Statement:
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the Manhattan distance between them:
|xi - xj| + |yi - yj|.

Return the minimum cost to make all points connected.
All points are connected if there is exactly one simple path between any two points.
*/

#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int absVal(int x) {
    return x < 0 ? -x : x;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int* minDist = (int*)malloc(pointsSize * sizeof(int));
    int* visited = (int*)calloc(pointsSize, sizeof(int));

    for (int i = 0; i < pointsSize; i++)
        minDist[i] = INT_MAX;

    minDist[0] = 0;
    int cost = 0;

    for (int i = 0; i < pointsSize; i++) {
        int u = -1;

        for (int j = 0; j < pointsSize; j++) {
            if (!visited[j] && (u == -1 || minDist[j] < minDist[u]))
                u = j;
        }

        visited[u] = 1;
        cost += minDist[u];

        for (int v = 0; v < pointsSize; v++) {
            if (!visited[v]) {
                int dist = absVal(points[u][0] - points[v][0]) + absVal(points[u][1] - points[v][1]);
                minDist[v] = min(minDist[v], dist);
            }
        }
    }

    free(minDist);
    free(visited);
    return cost;
}