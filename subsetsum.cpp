#include <bits/stdc++.h>
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &a)
{
    vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);
    prev[0] = 1;
    if (a[0] <= k)
    {
        prev[a[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = prev[target];
            bool take = false;
            if (a[i] <= target)
            {
                take = prev[target - a[i]];
            }
            curr[target] = take | nottake;
        }
        prev = curr;
    }
    return prev[k];
}