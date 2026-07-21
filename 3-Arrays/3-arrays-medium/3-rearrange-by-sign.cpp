// Given an integer array nums of even length consisting of an equal
// number of positive and negative integers.Return the answer array
// in such a way that the given conditions are met:
// - Every consecutive pair of integers have opposite signs.
// - For all integers with the same sign, the order in which
// they were present in nums is preserved.
// - The rearranged array begins with a positive integer.

// input
// 6
// -3 4 5 1 -4 -5

// output
// 4
// -3
// 5
// -4
// 1
// -5

// approach
// in new vector we already know that each pos and neg will be placed leaving
// one place in betn so we keep track of where pos and neg will and traverse throgh whole
// vector and if we find a pos then place it art posInd and increament by 2 same for neg
// and negInd because we know same sine elements will be at alternate

// revision
// remembered the cleaner approach correctly

#include <bits/stdc++.h>
using namespace std;

// optimal and cleaner
vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size(), pos = 0, neg = 1;
    vector<int> rearranged(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            rearranged[pos] = nums[i];
            pos += 2;
        }
        else
        {
            rearranged[neg] = nums[i];
            neg += 2;
        }
    }
    return rearranged;
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> output = rearrangeArray(nums);

    for (int out : output)
    {
        cout << out << endl;
    }

    return 0;
}