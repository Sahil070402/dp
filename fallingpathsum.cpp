#include <bits/stdc++.h>
using namespace std;

int ssp(int i, int j, vector<vector<int>> &matrix, int n, int m, vector<vector<int>> &dp)
{
    if (j < 0 || j >= m)
    {
        return -1e9;
    }
    if (i == 0)
    {
        return matrix[0][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = matrix[i][j] + ssp(i - 1, j, matrix, n, m, dp);
    int left = matrix[i][j] + ssp(i - 1, j - 1, matrix, n, m, dp);
    int right = matrix[i][j] + ssp(i - 1, j + 1, matrix, n, m, dp);
    return dp[i][j] = max(up, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e9;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, ssp(n - 1, j, matrix, n, m, dp));
    }
    return maxi;
}