#include <bits/stdc++.h>
using namespace std;

// problem statement : Given two sorted arrays nums1 and nums2, return
// an array that contains the union of these two arrays. The elements
// in the union must be in ascending order.
// The union of two arrays is an array where all values are distinct and
// are present in either the first array, the second array, or both.

// inputs
// 3 5
// 1 3 5
// 2 3 3 3 4

// output
// 1
// 2
// 3
// 4
// 5

// approach
// think like merge sort but we have to remove duplicates too
// so we have to check last element of arr before adding new element to it

// revision
// nailed it

// complexity
// time = O(m+n)
// space = O(m+n)

// initial approach but,
// missed some things like checking last element same or not,
// array size > 0 to check last element
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> nums;
    int m = nums1.size(), n = nums2.size();
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
        {
            if (nums.empty() || nums.back() != nums1[i])
                nums.push_back(nums1[i]);
            i++;
        }
        else
        {
            if (nums.empty() || nums.back() != nums2[j])
                nums.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m)
    {
        if (nums.back() != nums1[i])
            nums.push_back(nums1[i]);
        i++;
    }
    while (j < n)
    {
        if (nums.back() != nums2[j])
            nums.push_back(nums2[j]);
        j++;
    }

    return nums;
}

int main()
{
    vector<int> nums1, nums2;
    int n1, n2;
    cin >> n1 >> n2;
    nums1.reserve(n1);
    nums2.reserve(n2);
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        nums1.push_back(x);
    }
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        nums2.push_back(x);
    }

    vector<int> arr = unionArray(nums1, nums2);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}