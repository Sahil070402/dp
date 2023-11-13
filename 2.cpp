#include <bits/stdc++.h>
using namespace std;
long long ssm(int i, vector<int> &nums, vector<long long> &dp)
{
    if (i == 0)
    {
        return nums[0];
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    long long nottake = 0 + ssm(i - 1, nums, dp);
    long long take = nums[i] + ssm(i - 2, nums, dp);

    return dp[i] = max(take, nottake);
}
long long int houseRobber(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
    {
        return nums[0];
    }
    vector<int> ans1;
    vector<int> ans2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            ans1.push_back(nums[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            ans2.push_back(nums[i]);
        }
    }
    int n1 = ans1.size();
    int n2 = ans2.size();
    vector<long long> dp1(n1, -1);
    vector<long long> dp2(n2, -1);
    long long an1 = ssm(n1 - 1, ans1, dp1);
    long long an2 = ssm(n2 - 1, ans2, dp2);
    return max(an1, an2);
}