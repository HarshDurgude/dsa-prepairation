// Problem Statement : You are given an integer array arr of size n which contains
// both positive and negative integers. Your task is to find the length of the
// longest contiguous subarray with sum equal to 0.
// Return the length of such a subarray. If no such subarray exists, return 0.

// input
// 6
// 1 0 -4 3 1 0

// output
// 5

// approach
// its same as last problem we just find if current sum is found somewhere in the map

#include <bits/stdc++.h>
using namespace std;
// optimal solution for pos + neg
int subarraySum(vector<int> &nums, int k)
{

    int n = nums.size();
    unordered_map<int, int> mp;
    int count = 0;
    int prefix_sum = 0;
    mp[0] = 1; // for handling case where subarray is starting from 0

    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];

        auto it = mp.find(prefix_sum - k);
        if (it != mp.end())
        {
            count += it->second;
        }

        mp[prefix_sum]++;
    }

    return count;
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

    cout << subarraySum(nums, 2);

    return 0;
}
