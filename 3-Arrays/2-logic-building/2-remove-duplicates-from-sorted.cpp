#include <bits/stdc++.h>
using namespace std;

// problem statement : Given an integer array nums sorted in
// non-decreasing order, remove all duplicates in-place so
// that each unique element appears only once.
// Return the number of unique elements in the array.

// inputs
// 7
// 0 0 3 5 5 7 8

// output
// 0
// 3
// 5
// 7
// 8
// 0
// 5

// approach
// using for loop simplicity
// very intuative when u do the move-zeros-to-end
// using 2 pointer aproach, one to find the next non-duplicate
// element and one to tarck position of where non-duplicate
// element will go, similler to move zeros to end
// elements to shift to end get stacked up betn slow and fast pointer

// revision
// nailed it because prev problems and this one are pretty similler

// complexity
// time = O(n)
// space = O(1)

// initial approach (Worked), but self swaps
// int removeDuplicates1(vector<int> &nums)
// {
//     int j = 0;
//     for (int i = 1; i < nums.size(); i++)
//     {
//         if (nums[j] != nums[i])
//         {
//             swap(nums[++j], nums[i]);
//         }
//     }
//     return j + 1;
// }

// more cleaner avoids self swaps
int removeDuplicates(vector<int> &nums)
{
    int j = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[j])
        {
            j++;
            if (i != j)
            {
                swap(nums[i], nums[j]);
            }
        }
    }
    return j + 1;
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
    removeDuplicates(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}