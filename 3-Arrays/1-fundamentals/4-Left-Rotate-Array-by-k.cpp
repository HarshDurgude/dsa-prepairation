#include <bits/stdc++.h>
using namespace std;

// problem statement : Given an integer array nums and a
// non-negative integer k, rotate the array to the
// left by k steps.

// inputs
// 6
// 3
// 1 2 3 4 5 6

// output
// 4
// 5
// 6
// 1
// 2
// 3

// approach 1 (chaining)
// selecting an arr index and then placing
// it at correct position but keeping element present in
// that correct position in temp and then placing that temp in
// its correct position cycling like this and we would need
// gcd(n,k) cycles for cycling through every element of the
// array, because one cycle will most probably skip many elements
// gcd(n,k) cycles covers all elements

// approach 2 (reverse, better
// just reversing the first k elements then next n-k elemenst
// then all elements again, takes total [((k)+(n-k)) = [n/2]]
// + [(n) = [n/2]] = n, this solves the problem

// revision
// realised approach 2 is better to remember
// messsed up the reverse logic, at first used for instead of while

// complexity
// time = O(n) + O(lon(n)) = O(n)
// space = O(1)

// initial approach optimal but, (chaining)
// forgot to handle k>n, cycles beign skipped when
// gcd(k,n) is not 1 and didnt use modulo when
// movement wraps around an array
void leftRotateByK(vector<int> &nums, int k)
{
    if (nums.empty())
        return;

    int i, temp;
    k = k % nums.size();
    if (k == 0)
        return;

    for (int j = 0; j < gcd(k, nums.size()); j++)
    {
        i = j, temp = nums[j];
        do
        {
            i = (i - k + nums.size()) % nums.size();
            swap(temp, nums[i]);
        } while (i != j);
    }
}

// optimal and cleaner
void reverseArr(vector<int> &nums, int start, int end)
{

    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}
void rotateArray(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;

    if (n == 0 || k == 0)
    {
        return;
    }

    reverseArr(nums, 0, k - 1);

    reverseArr(nums, k, n - 1);

    reverseArr(nums, 0, n - 1);
}

int main()
{
    vector<int> nums;
    int n, k;
    cin >> n;
    cin >> k;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    // cout << "debug";
    rotateArray(nums, k);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }

    return 0;
}