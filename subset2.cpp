#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int ssp(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == 0)
    {
        if (arr[0] == 0 && target == 0)
        {
            return 2;
        }
        if (target == 0 || target == arr[0])
        {
            return 1;
        }
        return 0;
    }
    if (dp[i][target] != -1)
    {
        return dp[i][target];
    }
    int nottake = ssp(i - 1, target, arr, dp);
    int take = 0;
    if (arr[i] <= target)
    {
        take = ssp(i - 1, target - arr[i], arr, dp);
    }
    return dp[i][target] = (take + nottake) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return ssp(n - 1, k, arr, dp);
}