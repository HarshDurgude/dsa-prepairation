#include <bits/stdc++.h>
using namespace std;

// problem statement : Given two sorted arrays, nums1 and nums2,
// return an array containing the intersection of these two arrays.
// Each element in the result must appear as many times as it appears in
// both arrays; that is, if an element appears x times in nums1 and y
// times in nums2, it should appear min(x, y) times in the result.
// The intersection of two arrays is an array where all values are present
// in both arrays.

// inputs
// 6 6
// 1 2 2 3 3 3
// 2 3 3 4 5 7

// output
// 2
// 3
// 3

// approach
// traversing both arrays using 2 pointer approach if we find same then we
// we push back and increament both if we dont then we increamnet the smaller
// no need to keep checking after one array done traversing because i or j will
// not become n till n-1 is added and if n-1 is added then there wont appear
// any same element again

// complexity
// time = O(m+n)
// space = O(m+n)

// initial approach but,
// missed that we if one pointer goes out of arr then we cant find
// same elements after that so no need to check like prev prob
vector<int> intersectionArray(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    vector<int> nums;
    nums.reserve(nums1.size() + nums2.size());
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            nums.push_back(nums1[i]);
            i++;
            j++;
        }
        else
        {
            min(nums1[i], nums2[j]) == nums1[i] ? i++ : j++;
        }
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

    vector<int> arr = intersectionArray(nums1, nums2);
    // cout << "debug" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}