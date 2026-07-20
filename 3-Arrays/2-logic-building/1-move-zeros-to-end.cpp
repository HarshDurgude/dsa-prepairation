#include <bits/stdc++.h>
using namespace std;

// problem statement : Given an integer array nums,
// move all the 0's to the end of the array.
// The relative order of the other elements must remain the same.

// inputs
// 5
// 0 1 0 3 4

// output
// 1
// 3
// 4
// 0
// 0

// approach
// using for loop simplicity
// moving all the zeros to the end by one by one swapping
// zeros with its next non zero elements, one counter for where the next non
// zero elemnet will go and one for next non-zero elemnet, it
// becomes a fast-slow 2 pointer approach and all the zeros get in betn
// of slow and fast so increamenting slow will always automatically
// point to where next non zero should go

// revision
// selected the more intuative aproach
// while or for doest matter

// complexity
// time = O(n)
// space = O(1)

void moveZeroes(vector<int> &nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            if (i != j)
            {
                swap(nums[i], nums[j]);
            }
            j++;
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
    moveZeroes(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}