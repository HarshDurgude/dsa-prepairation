// Problem Statement : A permutation of an array of integers is an arrangement of
// its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr:
// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically
// greater permutation of its integers.
// More formally, if all the permutations of the array are sorted in lexicographical
// order, then the next permutation of that array is the permutation that follows it in the
// sorted order.
// If such arrangement is not possible (i.e., the array is the last permutation), then
// rearrange it to the lowest possible order (i.e., sorted in ascending order).
// You must rearrange the numbers in-place and use only constant extra memory.

// input
// 3
// 3 2 1

// output
// 1 2 3

// approach
// permutations will be the all possible numbers from array elements in a sorted way,
// solving this problem depends on if u know the hidden trick/observation or not,
// trick is that we check the elements from right to left for assending order
// and where it breaks the order thats where we find the pivot and then find the
// element just bigger than that then we swap them and reverse the assending to make it
// dessending to get just bigger number than that

#include <bits/stdc++.h>
using namespace std;

// optimal approach
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot = -1, ind = n;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            for (int j = n - 1; j > i; j--)
            {
                if (nums[pivot] < nums[j])
                {
                    ind = j;
                    break;
                }
            }
            break;
        }
    }

    if (pivot >= 0)
    {
        swap(nums[pivot], nums[ind]);
        reverse(nums.begin() + pivot + 1, nums.end());
    }
    else
    {
        reverse(nums.begin(), nums.end());
    }
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

    nextPermutation(nums);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    // func call here

    return 0;
}