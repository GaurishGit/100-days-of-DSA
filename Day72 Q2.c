using System;

/*
Problem Statement:
Given a 2D matrix cost[][] of size n where cost[i][j] denotes the cost of moving from city i to city j.
Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then return back to city 0 at minimum cost.
*/

class Solution {
    int n;
    int[,] dp = new int[16, 1 << 16];

    int Min(int a, int b) {
        return a < b ? a : b;
    }

    int TspUtil(int mask, int pos, int[,] cost) {
        if (mask == (1 << n) - 1)
            return cost[pos, 0];

        if (dp[pos, mask] != -1)
            return dp[pos, mask];

        int ans = int.MaxValue;

        for (int city = 0; city < n; city++) {
            if ((mask & (1 << city)) == 0) {
                int newAns = cost[pos, city] + TspUtil(mask | (1 << city), city, cost);
                ans = Min(ans, newAns);
            }
        }

        return dp[pos, mask] = ans;
    }

    public int tsp(int[,] cost) {
        n = cost.GetLength(0);

        for (int i = 0; i < 16; i++)
            for (int j = 0; j < (1 << 16); j++)
                dp[i, j] = -1;

        return TspUtil(1, 0, cost);
    }
}