#include <bits/stdc++.h>
using namespace std;

// problem statement : Given a binary array nums, return
// the maximum number of consecutive 1s in the array.

// inputs
// 5
// 1 1 1 0 1

// output
// 3

// approach
// iterate through the array, keep a counter
// and count ones but reset it when found 0
// and also keep a counter to store max of the counts

// revision
// didnt miss anything

// initial approach (worked) but,
// missed maxi which keeps track of max occurances
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size(), globalMaxOnes = 0, maxOnes = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 1)
        {
            maxOnes++;
            globalMaxOnes = max(maxOnes, globalMaxOnes);
        }
        else
        {
            maxOnes = 0;
        }
    }
    return globalMaxOnes;
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
    cout << findMaxConsecutiveOnes(nums);

    return 0;
}