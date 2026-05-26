// Problem Statement : Given an integer array nums of size n, return the majority
// element of the array. The majority element of an array is an element that appears more
// than n/2 times in the array. The array is guaranteed to have a majority element.

// input
// 6
// 1 1 1 2 1 3

// output
// 1

// approach
// If majority element appears more than n/2 time so if we repeatedly cancle 1 major element
// with 1 non-major element the majority will still surview
// Keep a count variable while iterating, Increase count when encountering the same
// candidate. Decrease count when encountering a different number. If count == 0,
// change candidate. The final candidate will be the majority element.

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int major, count = 0; // try to make initial values 0 or non dependant on array as array could be empty
    for (int i = 0; i < nums.size(); i++)
    {

        if (count == 0)
        {
            major = nums[i];
            count = 1;
        }
        else
        {
            count += nums[i] == major ? 1 : -1;
        }
    }
    return major;
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
    cout << majorityElement(nums);

    return 0;
}