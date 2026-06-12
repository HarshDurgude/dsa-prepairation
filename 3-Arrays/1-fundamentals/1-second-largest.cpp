#include <bits/stdc++.h>
using namespace std;
// problem statement : Given an array of integers
// nums, return the second-largest element in the array.
// If the second-largest element does not exist,
// return -1.

// inputs
// 5
// 1 1 1 1 1

// output
// -1

// approach
// iterate to find largest and when finding a even larger
// num update seclarge to large and large to new number
// NOTE - if itration not greater than largest then it could be betn
// large and seclarge or could be equal to large, check that too

// revision
// solved correctly but,
// almost missed the edge case of largest and its right being equal

// initial aproach : optimal, but
// missed the edge case of second largest being on the right of
// the largest and largest and its right being equal
int secondLargestElement(vector<int> &nums)
{
    int n = nums.size(), largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if (nums[i] > secondLargest && nums[i] != largest)
        {
            secondLargest = nums[i];
        }
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
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

    cout << secondLargestElement(nums);

    return 0;
}