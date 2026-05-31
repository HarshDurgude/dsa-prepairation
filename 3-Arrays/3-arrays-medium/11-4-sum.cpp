// Problem Statement : Given an integer array nums and an integer target. Return all
// quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// a, b, c, d are all distinct valid indices of nums.
// nums[a] + nums[b] + nums[c] + nums[d] == target.
// Notice that the solution set must not contain duplicate quadruplets. One element
// can be a part of multiple quadruplets. The output and the quadruplets can be
// returned in any order.

// input
// 6 7
// 1 -2 3 5 7 9

// output
// -2 1 3 5

// approach 1
// derived from the approach 2 of the prev problem, we didnt use approach 1 because
// when we dont need indexes it doesnt make sense to use it, because it increases complexity,
// this approach is already intuative when u know the prev sorting approach we just use the
// target value here for the comaprision instead of 0 like before

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    // cout << nums[i] << nums[j] << nums[left] << nums[right];
                    right--;
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (nums[i] + nums[j] + nums[left] + nums[right] > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums;
    int n, t;
    cin >> n >> t;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    vector<vector<int>> out = fourSum(nums, t);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}