// Problem Statement : Given an integer array nums. Find the subarray with
// the largest product, and return the product of the elements present in
// that subarray.
// A subarray is a contiguous non-empty sequence of elements within an array.

// input
// 3
// -5 0 -2

// output
// 0

// approach
// as we can have negatives and 0 in our input, so product of all elements wont be
// the maximum, to find max we have to traverse and multiply current to the product just
// like sum but if we find 0 then we reset the product to 1 and repeat, but for the negatives
// we also have to traverse from the back with productReverse because in case of negatives
// we can still have max product but we need even number of negatives for that, so just
// traversing from front will miss those edge cases and in each iteration we set maxProduct
// to maximum of maxProduct,product,productReverse

#include <bits/stdc++.h>
using namespace std;

// initial approach worked but,
// can be optimised a lil bit more
int maxProduct1(vector<int> &nums)
{
    long long product = nums[0], maxP = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (product == 0)
        {
            product = 1;
        }

        product *= nums[i];

        maxP = max(maxP, product);
    }
    product = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (product == 0)
        {
            product = 1;
        }

        product *= nums[i];

        maxP = max(maxP, product);
    }

    return int(maxP);
}

// optimal solution
int maxProduct2(vector<int> &nums)
{
    long long product = 1, productReverse = 1, maxP = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (product == 0)
        {
            product = 1;
        }

        if (productReverse == 0)
        {
            productReverse = 1;
        }
        product *= nums[i];
        productReverse *= nums[n - i - 1];
        maxP = max(maxP, max(product, productReverse));
    }

    return int(maxP);
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

    cout << maxProduct2(nums);

    return 0;
}