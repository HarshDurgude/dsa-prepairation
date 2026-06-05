// Problem Statement : Given an integer array nums. Return the number of reverse pairs
// in the array.
// An index pair (i, j) is called a reverse pair if:
// - 0 <= i < j < nums.length
// - nums[i] > 2 * nums[j]

// input
// 5
// 6 4 1 2 7

// output
// 3

// approach
// also uses merge sort but kinda diffrent, we cant directly integrate the counter step
// inside the merge sort stpes, we have to add a new function that runs before merge
// so that we have two sorted array to work with and this new function iterates through
// one array and increament the counter as we find pair, but logic for this func is
// is not very intuative, it basically based on the idea that in a sorted array if we found
// arr[i] > 2*arr[j] then all elements next to arr[i] will also be greater than 2*arr[j]

#include <bits/stdc++.h>
using namespace std;

// optimal approach

void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    vector<int> temp;
    while ((i < mid + 1) && j < high + 1)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {

            temp.push_back(arr[j]);

            j++;
        }
    }
    // adding remaining elements on either side directly
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

int countReversePairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid + 1;
    for (int i = low; i < mid + 1; i++)
    {
        while (right <= high && arr[i] > (long long)2LL * arr[right])
        {
            right++;
        }
        cnt += right - (mid + 1);
    }

    return cnt;
}

int merge_sort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    cnt += merge_sort(arr, low, mid);
    cnt += merge_sort(arr, mid + 1, high);

    cnt += countReversePairs(arr, low, mid, high);
    merge(arr, low, mid, high);

    return cnt;
}

int reversePairs(vector<int> nums)
{
    int n = nums.size();

    return merge_sort(nums, 0, n - 1);
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

    cout << reversePairs(nums);

    return 0;
}