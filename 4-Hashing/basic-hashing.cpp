#include <bits/stdc++.h>
using namespace std;

int sumHighestAndLowestFrequency(vector<int> &nums)
{

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    int maxCnt = 0;
    int minCnt = INT_MAX;

    for (auto x : mp)
    {
        if (x.second > maxCnt)
        {
            maxCnt = max(maxCnt, x.second);
        }
        if (x.second < minCnt)
        {
            minCnt = min(minCnt, x.second);
        }
    }

    return maxCnt + minCnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << sumHighestAndLowestFrequency(nums);

    return 0;
}