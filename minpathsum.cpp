#include <bits/stdc++.h>
using namespace std;
int minSumPath(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[i][j] = grid[i][j];
      }
      else
      {
        int l_sum = 1e9;
        int r_sum = 1e9;
        if (j > 0)
        {
          l_sum = grid[i][j] + dp[i][j - 1];
        }
        if (i > 0)
        {
          r_sum = grid[i][j] + dp[i - 1][j];
        }
        dp[i][j] = min(l_sum, r_sum);
      }
    }
  }
  return dp[n - 1][m - 1];
}