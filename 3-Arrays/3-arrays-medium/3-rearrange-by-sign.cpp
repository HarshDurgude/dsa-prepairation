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

#include <bits/stdc++.h>
using namespace std;

// initial approach worked but,
// more complex, extra searching, same
// complexity but extra unit oprations and not cleaner logic
vector<int> rearrangeArray1(vector<int> &nums)
{
    vector<int> li;
    int i = 0, j = 0;
    while (i < nums.size() && j < nums.size())
    {
        if (nums[i] > 0 && nums[j] < 0)
        {
            li.push_back(nums[i++]);
            li.push_back(nums[j++]);
        }
        else
        {
            if (nums[i] < 0)
            {
                i++;
            }

            if (nums[j] > 0)
            {
                j++;
            }
        }
    }
    return li;
}

// optimal and cleaner
vector<int> rearrangeArray2(vector<int> &nums)
{
    int n = nums.size();

    // Initialize a result vector of size n
    vector<int> ans(n, 0);

    // Initialize indices for positive and negative elements
    int posIndex = 0, negIndex = 1;

    // Traverse through each element in nums
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {

            /* If current element is negative, place
            it at the next odd index in ans*/
            ans[negIndex] = nums[i];

            // Move to the next odd index
            negIndex += 2;
        }
        else
        {
            ans[posIndex] = nums[i];

            // Move to the next even index
            posIndex += 2;
        }
    }

    // Return the rearranged array
    return ans;
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
    vector<int> output = rearrangeArray2(nums);

    for (int out : output)
    {
        cout << out << endl;
    }

    return 0;
}