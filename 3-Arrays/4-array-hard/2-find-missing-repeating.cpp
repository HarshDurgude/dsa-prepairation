// Problem Statement : Given an integer array nums of size n containing values
// from [1, n] and each value appears exactly once in the array, except for A,
// which appears twice and B which is missing.
// Return the values A and B, as an array of size 2, where A appears in the 0-th
// index and B in the 1st index.
// Note: You are not allowed to modify the original array.

// input
// 7
// 1 2 3 6 7 5 7

// output
// 7 4

// approach
// hidden trick/formula involved - sum of squares of 1st n natural numbers formula
// gives an addinal quadratic eqution with the normal eq that inolves expected sum,
// actuall sum, A, B, so now we have 2 equations and 2 unknowns(A,B), and these definetly
// can be solved [actuallSum - A + B = expectedSum] same format for the squares one

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> nums)
{
    int n = nums.size();

    long long expectedSum = 1LL * n * (n + 1) / 2;

    long long expectedSqSum = 1LL * n * (n + 1) * (2LL * n + 1) / 6;

    long long sum = 0, sqSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        sqSum += 1LL * nums[i] * nums[i];
    }

    long long A, B;

    A = (((expectedSqSum - sqSum) / (expectedSum - sum)) + (sum - expectedSum)) / 2;

    B = A + expectedSum - sum;

    return {(int)A, (int)B};
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

    vector<int> out = findMissingRepeatingNumbers(nums);

    cout << out[0] << " ";
    cout << out[1];

    return 0;
}