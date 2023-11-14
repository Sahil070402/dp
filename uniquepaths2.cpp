#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int ls = 0;
                int rs = 0;

                if (i > 0)
                    ls = dp[i - 1][j];
                if (j > 0)
                    rs = dp[i][j - 1];
                dp[i][j] = (ls + rs) % mod;
            }
        }
    }
    return dp[n - 1][m - 1];
}