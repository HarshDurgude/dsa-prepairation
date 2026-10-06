// Problem Statement :Given an array of integers nums and an integer k, return
// the total number of subarrays whose sum equals to k.

// input
// 3
// 1 1 1

// output
// 2

// approach
// so in the map instead of storing the index we store the count of how many times the
// same (prefix_sum - k) appears while traversing, and we just increase it by one every time
// we find it and add it to counter

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
