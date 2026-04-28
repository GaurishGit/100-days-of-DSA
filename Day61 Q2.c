/*
547. Number of Provinces

Problem:
There are n cities. Some of them are connected, while some are not. 
If city a is connected directly with city b, and city b is connected directly with city c, 
then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and jth city 
are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

void dfs(int** isConnected, int n, int* visited, int city) {
    for(int j = 0; j < n; j++) {
        if(isConnected[city][j] == 1 && !visited[j]) {
            visited[j] = 1;
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {
    int visited[isConnectedSize];
    for(int i = 0; i < isConnectedSize; i++) visited[i] = 0;

    int provinces = 0;

    for(int i = 0; i < isConnectedSize; i++) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(isConnected, isConnectedSize, visited, i);
            provinces++;
        }
    }

    return provinces;
}