#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int maxsum(int *arr, int i)
    {
        if (i == 0)
        {
            return arr[i];
        }
        if (i < 0)
        {
            return 0;
        }
        int left = arr[i] + maxsum(arr, i - 2);
        int right = 0 + maxsum(arr, i - 1);
        return max(left, right);
    }
    int findMaxSum(int *arr, int n)
    {
        return maxsum(arr, n - 1);
    }
};

// memoization

class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int maxsum(int *arr, int i, vector<int> &dp)
    {
        if (i == 0)
        {
            return arr[i];
        }
        if (i < 0)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int left = arr[i] + maxsum(arr, i - 2, dp);
        int right = 0 + maxsum(arr, i - 1, dp);
        return dp[i] = max(left, right);
    }
    int findMaxSum(int *arr, int n)
    {
        vector<int> dp(n, -1);
        return maxsum(arr, n - 1, dp);
    }
};

// space optimize approach

class Solution
{

    int findMaxSum(int *arr, int n)
    {

        int prev1 = arr[0];
        int prev2 = 0;
        for (int ind = 1; ind <= n - 1; ind++)
        {

            int ls = arr[ind];
            if (ind > 1)
                ls += prev2;
            int rs = 0 + prev1;
            int curr = max(rs, ls);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};