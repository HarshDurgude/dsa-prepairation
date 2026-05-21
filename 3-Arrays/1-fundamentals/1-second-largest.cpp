#include <bits/stdc++.h>
using namespace std;
// problem statement : Given an array of integers
// nums, return the second-largest element in the array.
// If the second-largest element does not exist,
// return -1.

// inputs
// 5
// 1 1 1 1 1

// output
// -1

// approach
// iterate to find largest and when finding a even larger
// num update seclarge to large and large to new number
// NOTE - if itration not greater than largest then it could be betn
// large and seclarge, check that too

// initial aproach : optimal, but
// missed the edge case of second largest being on the right of
// the largest and laegest and its right being equal
int secondLargest(vector<int> &arr, int n)
{
    int largest = INT_MIN, secondLargest = INT_MIN;
    // INT_MIN used because if largest=arr[0] then inputing empty array will crash
    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    arr.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << secondLargest(arr, n);

    return 0;
}