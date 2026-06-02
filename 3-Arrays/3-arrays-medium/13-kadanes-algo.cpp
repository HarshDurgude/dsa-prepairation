// Problem Statement : Given an integer array nums, find the subarray
// with the largest sum and return the sum of the elements present in
// that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

// input
// 6
// 2 3 5 -2 7 -4

// output
// 2 3 5 -2 7

// approach
// this approach is all about knowing the behaviour of the pattern, we just keep
// basic idea is we dont include the subarray part which contributes negatively to our
// overall subarray then if the current subarray is adding even 1/0 then also its importatnt
// adding current elements to a currentMax variable and if gets bigger than globalMax
// then we override globalmax with it, but if currentMax goes negative then we again
// start fresh with a new subarray, starting from next element,
// so currentMax resets to 0

#include <bits/stdc++.h>
using namespace std;

// optimal aproach,
// intuative when know the approach
int maxSubArray(vector<int> &nums)
{
    int currentMax, globalMax;
    currentMax = 0;
    globalMax = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        currentMax += nums[i];
        globalMax = max(currentMax, globalMax);

        if (currentMax < 0)
        {
            currentMax = 0;
        }
    }
    return globalMax;
}

// follow up Que : Can you print the subarray that has the max sum ?
void printMaxSubArray(vector<int> &nums)
{
    int currentMax, globalMax, low = 0, high = 0, start = 0;
    currentMax = 0;
    globalMax = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        currentMax += nums[i];

        if (currentMax > globalMax)
        {
            globalMax = currentMax;
            high = i;
            low = start;
        }

        if (currentMax < 0)
        {
            currentMax = 0;
            start = i + 1;
        }
    }
    for (int i = low; i <= high; i++)
    {
        cout << nums[i] << " ";
    }
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

    printMaxSubArray(nums);

    return 0;
}