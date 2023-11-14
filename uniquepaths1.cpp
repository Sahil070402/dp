#include <bits/stdc++.h>
using namespace std;
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
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
                dp[i][j] = (ls + rs);
            }
        }
    }
    return dp[m - 1][n - 1];
}