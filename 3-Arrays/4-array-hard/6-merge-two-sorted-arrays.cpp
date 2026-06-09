// Problem Statement : Given two integer arrays nums1 and nums2. Both arrays are
// sorted in non-decreasing order.
// Merge both the arrays into a single array sorted in non-decreasing order.
// - The final sorted array should be stored inside the array nums1 and it should
// be done in-place.
// - nums1 has a length of m + n, where the first m elements denote the elements
// of nums1 and rest are 0s.
// - nums2 has a length of n.

// input
// 4 3
// -5 -2 4 5
// -3 1 8

// output
// -5-3-21458

// approach
// so both of these approaches do the exact same thing, but the main idea here is that
// we have to start filling the largest elements at the back of nums1 first because
// they are empty and we wont need to worry about swap or temp vars, so we can
// traverse from the n-1 of nums1 and fill the element which is bigger from i1 and i2
// i1 start from m-1 and i2 from n-1, and our base condition will be i2 going below 0
// because remaining elements in nums1 will be on their position already

#include <bits/stdc++.h>
using namespace std;

// initial approach, already optimal but kind of long code
void merge1(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i1 = m - 1, i2 = n - 1;

    for (int i = m + n - 1; i >= 0; i--)
    {
        if (i1 < 0)
        {
            nums1[i] = nums2[i2];
            i2--;
        }
        else if (i2 < 0)
        {
            break;
        }
        else
        {

            if (nums1[i1] >= nums2[i2])
            {
                nums1[i] = nums1[i1];
                i1--;
            }
            else
            {
                nums1[i] = nums2[i2];
                i2--;
            }
        }
    }
}

// more clean and short
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i1 = m - 1, i2 = n - 1;
    int i = n + m - 1;

    // Until all the elements from nums2 are placed
    while (i2 >= 0)
    {
        // If nums1[i] >= nums2[j]
        if (i1 >= 0 && nums1[i1] >= nums2[i2])
        {
            // Place the element
            nums1[i] = nums1[i1];

            // Move both indices back by one place
            i--, i1--;
        }
        // Otherwise
        else
        {
            // Place the element
            nums1[i] = nums2[i2];

            // Move both indices back by one place
            i--, i2--;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m + n), nums2(n);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        nums1[i] = x;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums2[i] = x;
    }

    merge2(nums1, m, nums2, n);

    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i];
    }
    return 0;
}