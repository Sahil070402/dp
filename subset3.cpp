#include <bits/stdc++.h>
using namespace std;
int modulo = 1e9 + 7;
int css(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
{

    if (i == 0)
    {
        if (arr[i] == 0 && sum == 0)
        {
            return 2;
        }
        if (sum == 0 || arr[0] == sum)
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][sum] != -1)
    {
        return dp[i][sum];
    }
    int notpick = css(i - 1, sum, arr, dp);
    int pick = 0;
    if (arr[i] <= sum)
    {
        pick = css(i - 1, sum - arr[i], arr, dp);
    }
    return dp[i][sum] = ((pick + notpick) % modulo);
}
int perfectSum(vector<int> &arr, int n, int sum)
{

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return css(n - 1, sum, arr, dp);
}
int countPartitions(int n, int d, vector<int> &a)
{
    int ts = 0;
    for (int i = 0; i < n; i++)
    {
        ts += a[i];
    }
    if (ts - d < 0 || (ts - d) % 2)
    {
        return 0;
    }
    else
    {
        perfectSum(a, n, (ts - d) / 2);
    }
}