#include <bits/stdc++.h>
using namespace std;

// problem statement : Given an integer array of size n containing
// distinct values in the range from 0 to n (inclusive),
// return the only number missing from the array within this range.

// inputs
// 7
// 0 1 2 3 4 6 7

// output
// 5

// approach
// sum approach is very intuative coparaing the sum of n natural nums
// to sum of array elements, also remember the xor approach

// revision
// very easy

// complexity
// time = O(n)
// space = O(1)

// initial approach also optimal
// sum
int findMissing(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    return ((n * (n + 1)) / 2) - sum;
}

// alternate approach (optimal)
// XOR
// int missingNumber(vector<int>& nums) {
//     int xor1 = 0, xor2 = 0;
//     // Calculate XOR of all array elements
//     for (int i = 0; i < nums.size(); i++) {
//         xor1 = xor1 ^ (i + 1); //XOR up to [1...N]
//         xor2 = xor2 ^ nums[i]; // XOR of array elements
//     }
//     // XOR of xor1 and xor2 gives missing number
//     return (xor1 ^ xor2);
// }

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
    cout << findMissing(nums);

    return 0;
}