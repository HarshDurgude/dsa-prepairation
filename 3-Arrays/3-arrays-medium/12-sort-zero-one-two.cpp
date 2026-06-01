// Problem Statement : Given an array nums consisting of only 0, 1, or 2.
// Sort the array in non-decreasing order.
// The sorting must be done in-place, without making a copy of the original array.

// input
// 6
// 2 2 1 0 0 1

// output
// 0
// 0
// 1
// 1
// 2
// 2

// approach
// can be related to the move zeros to the end approach but, that has only two
// partitions and traversal from only one side but this has more partitions and
// traversals from both directions, we can use low, mid and high, low tracks where
// next zero zero should go simillerly mid for 1 and high for 2, mid will be the main
// traversal variable, if mid 0 swap with low, if 2 swap with high, if 1 then nothing
// increament and decreament carefully, cause we dont know what will we get after
// swaping with high(non traversed area), but swaping with low will def give 1

#include <bits/stdc++.h>
using namespace std;

// self derived approach, but doesnt work
// fails for many edge cases
void sortZeroOneTwo1(vector<int> &nums)
{
    int zero, one;
    zero = one = 0;

    for (int i = 0; i < nums.size() && one < nums.size() && zero < nums.size(); i++)
    {

        if (nums[i] == 0)
        {
            swap(nums[i], nums[one]);
            swap(nums[one], nums[zero]);
            zero++;
            one++;
        }
        else if (nums[i] == 1)
        {
            swap(nums[i], nums[one]);
            one++;
        }

        if (one <= zero)
        {
            if (nums[zero] == 1)
                one = zero + 1;
            else
            {
                one = zero;
            }
        }
    }
}

// optimal approach, also called dutch national flag algorithm
void sortZeroOneTwo2(vector<int> &nums)
{
    int low, mid, high;
    low = mid = 0;
    high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] > 1)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
        else
        {
            mid++;
        }
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

    sortZeroOneTwo2(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}