// Problem Statement : Given an array of integers nums and an integer k,
// return the total number of subarrays whose XOR equals to k.

// input
// 5
// 5 6 7 8 9

// output
// 2

// approach
// just like last approach instead of increamenting prefix_sum we increament
// prefix_xor and check if prefix_xor ^ k exists in the map and if it does
// then we increament the count and we also do map[prefix_xor]++ in the end
// for maintaining correct count for furthur oprations

#include <bits/stdc++.h>
using namespace std;
// optimal solution for pos + neg
int subarraysWithXorK(vector<int> &nums, int k)
{

    int n = nums.size();
    unordered_map<int, int> mp;
    int count = 0;
    int prefix_xor = 0;
    mp[0] = 1; // for handling case where subarray is starting from 0

    for (int i = 0; i < n; i++)
    {
        prefix_xor ^= nums[i];

        auto it = mp.find(prefix_xor ^ k);
        if (it != mp.end())
        {
            count += it->second;
        }

        mp[prefix_xor]++;
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

    cout << subarraysWithXorK(nums, 5);

    return 0;
}
