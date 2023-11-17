#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &a, int n)
{
    int ts = 0;
    for (int i = 0; i < n; i++)
    {
        ts += a[i];
    }
    vector<vector<int>> dp(n, vector<int>(ts + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (a[0] <= ts)
    {
        dp[0][a[0]] = true;
    }
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= ts; target++)
        {
            bool nottake = dp[i - 1][target];
            bool take = false;
            if (a[i] <= target)
            {
                take = dp[i - 1][target - a[i]];
            }
            dp[i][target] = take | nottake;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= ts / 2; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int s1 = i;
            int s2 = ts - i;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}