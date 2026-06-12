#include <bits/stdc++.h>
using namespace std;

// problem statement : Given an integer array
// nums, rotate the array to the left by one.
// Note: There is no need to return
// anything, just modify the given array.

// inputs
// 5
// 1 2 3 4 5

// output
// 2
// 3
// 4
// 5
// 1

// approach
// iterate through the array, start from 1 to
// n-1, in each iteration store current element
// at prev index by doing this first element will
// get lost so store it in temp at start and restore
// ist proper position at end

// revision
// nothing missed

// initial approach but,
// initially stored last element instead of first
// and overcomplicated nums[i-1]=nums[i]
void rotateArrayByOne(vector<int> &nums)
{
    int temp = nums[0], n = nums.size();

    for (int i = n - 1; i >= 0; i--)
    {
        swap(temp, nums[i]);
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

    rotateArrayByOne(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}