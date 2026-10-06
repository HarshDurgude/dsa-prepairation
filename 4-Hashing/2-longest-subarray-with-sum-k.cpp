// Problem Statement : Given an array nums of size n and an integer k,
// find the length of the longest sub-array that sums to k. If no
// such sub-array exists, return 0.

// input
// 9
// -38 534 204 -848 -223 -762 767 277 -717

// output
// 4

// approach
// using unordered map to store sum till current element for each each
// element as we traverse then at each new element we can just check if
// current sum - k exists in map or not if it exists then from index where
// sum - k is found to current index is an subarray which sums up to k
// like this we find the sub array with greatest lenght by the local max
// and global max technique

// hint 1
// Use a hash map to store the prefix sum of the array at each index.
// This helps efficiently track subarrays that sum to k.

// hint 2
// For each index i, calculate the prefix sum up to that point. If the
//  prefix sum minus k exists in the hash map, the subarray between
//  those indices sums to k.

#include <bits/stdc++.h>
using namespace std;
// optimal solution for pos + neg
int longestSubarray(vector<int> &nums, int k)
{

    int n = nums.size();
    unordered_map<int, int> mp;
    int maxLength = 0;
    int prefix_sum = 0;
    mp[0] = -1; // for handling case where subarray is starting from 0

    for (int i = 0; i < n; i++)
    {
        prefix_sum += nums[i];

        auto it = mp.find(prefix_sum - k);
        if (it != mp.end())
        {
            maxLength = max(maxLength, i - it->second);
        }

        if (mp.find(prefix_sum) == mp.end())
        {

            mp[prefix_sum] = i;
        }
    }

    return maxLength;
}

// only optimal for pos
int longestSubarrayPos(vector<int> &nums, int k)
{
    int n = nums.size(), sum = 0, j = 0, globalMax = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        while (sum > k && j < i)
        {
            sum -= nums[j];
            j++;
        }
        if (sum == k)
        {
            globalMax = max(i - j + 1, globalMax);
        }
    }
    return globalMax;
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

    cout << longestSubarrayPos(nums, 6);

    return 0;
}
