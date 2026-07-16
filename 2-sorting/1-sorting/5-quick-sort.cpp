#include <bits/stdc++.h>
using namespace std;

// Problem Statement: quick sort

// input
// 7
// 5 4 9 2 3 1 8

// output
// 1
// 2
// 3
// 4
// 5
// 8
// 9

// Approach
// randomly choosing(first for simplicity) an element and making
// it the pivot then placing the pivot at its right position
// finding the right position by two simulteneous iterations
// one from start and one from end, from start we check if
// current > pivot and increament till we find one, then from end
// we check if current < pivot and decreament till we find one, then
// if still start < end we swap them by doing this repeatedly we will get
// smaller than pivot to left side and greater at right, then doing
// this recrsively for left and right part will sort entire array

// revision
// missed :
// * if (low >= high), at first did if (low == high)
// * && i <= high - 1, && j >= low + 1, missed the 2nd conditions for
// while loops
// *** only one condition from i or j will have equal condition(not both
// <=, >= ❌ ) because we have to move duplicate elements to one side
// * i = low, initially did i = low+1 but when low and high have one
// number diff. then low + 1 becomes high so intially condition(i<j)
// becomes false and while never runs

// complexity
// space =O(1), if we consider auxilary space for recursion stack then O(n)
// time = O(N*Log2(N))

// optimal approach
int partition(vector<int> &arr, int low, int high)
{
    int i = low, j = high;
    while (i < j)
    {
        while (arr[low] >= arr[i] && i <= high - 1)
        {
            i++;
        }

        while (arr[low] < arr[j] && j >= low + 1)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);

    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }

    // partition
    int mid = partition(arr, low, high);
    quick_sort(arr, low, mid - 1);
    quick_sort(arr, mid + 1, high);
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}