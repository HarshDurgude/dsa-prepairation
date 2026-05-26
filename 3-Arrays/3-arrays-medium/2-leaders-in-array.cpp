// Given an integer array nums, return a list of all the leaders in the array.
// A leader in an array is an element whose value is strictly greater than all
// elements to its right in the given array. The rightmost element is always a
// leader. The elements in the leader array must appear in the order they appear
// in the nums array.

// input
// 6
// -3 4 5 1 -4 -5

// output
// 5
// 1
// -4
// -5

// approach
// we can start traversing from right so we can keep track of the largest and compare
// with current if greater than max then we can add to new list and update max
// reversing the list at the end casue we will use push_back, uisng INT_MIN so that
// end element is always included

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
    vector<int> leaders;
    int max = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > max)
        {
            leaders.push_back(nums[i]);
            max = nums[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
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
    vector<int> output = leaders(nums);

    for (int out : output)
    {
        cout << out << endl;
    }

    return 0;
}