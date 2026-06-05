// Problem Statement : Given an integer array nums. Return the number
// of inversions in the array.
// Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
// It indicates how close an array is to being sorted.
// A sorted array has an inversion count of 0.
// An array sorted in descending order has maximum inversion.

// input
// 4
// 9 5 4 2

// output
// 6

// approach
// solution to this problem is excat same as merge sort we just ad a counter
// variable in mergesort which keeps track of inversions, so how it works is we
// still sort the array using merge sort and when its time of merging we have i and j
// if arr[i] > arr[j] then we increase the counter but not just by 1 but as left
// array is already sorted next elements in the line will also be greater than arr[j]
// so we increase counter by (mid - i + 1) and return the counter with each func
// merge, mergesort then numberOfInversions, we also have to use long long int as
// counter could be a big value too also have to modify base case of mergesort
// recurrsion cause we are now returning something

#include <bits/stdc++.h>
using namespace std;

// optimal approach
long long int merge(vector<int> &arr, int low, int mid, int high)
{
    long long int cnt = 0;
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

            cnt += (mid - i + 1);
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
    return cnt;
}

long long int merge_sort(vector<int> &arr, int low, int high)
{
    long long int cnt = 0;
    if (low >= high)
        return 0;

    int mid = (low + high) / 2;
    cnt += merge_sort(arr, low, mid);
    cnt += merge_sort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);

    return cnt;
}

long long int numberOfInversions(vector<int> nums)
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

    cout << numberOfInversions(nums);

    return 0;
}