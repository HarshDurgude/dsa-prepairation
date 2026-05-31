// Problem Statement : Given an array of integers nums and an integer target. Return the
// indices(0 - indexed) of two elements in nums such that they add up to target.
// Each input will have exactly one solution, and the same element cannot be used twice.
// Return the answer in any order.

// input
// 6
// 2 -2 0 3 -3 5

// output
// -3 -2 5
// -3 0 3
// -2 0 2

// approach 1
// derived from the 2-sum non sorting approach, as we have a target there we have zero here
// so we can consider this as traversing with i and now -nums[i] becomes target and the remaining
// vector becomes nums for 2 sum because we have to now find 2 elements whose sum is -nums[i]
// but here we dont care abt indexs so we can use more optimal data structure than maps like set
// to store trversed elements, but the triplets that we have to return they cant be duplicate so we need to
// sort before we add them into the result, and result should also bea set so no duplicates

// approach 2
// derived from the sorting solution of the 2 sum so same like before we can break this problem down into
// a normal traversal with i and a 2 sum problem like we have array next to i as input array for two sum
// but this has some more advantages like we dont need to use repeated sets to store visited and also
// no worry of checking duplicates as sorted vector will return even duplicates in same order so we just add
// some conditions to check our current values of i left and right are not equal to prev ones, so we can
// directly add triplets into a vector instead of a set

#include <bits/stdc++.h>
using namespace std;

// initial approach, optimal but
// looked at solution then discovered,
// time = O(N2), space = O(N) + O(no. of triplets)
vector<vector<int>> threeSum1(vector<int> &nums)
{
    set<vector<int>> result;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> visited;
        for (int j = i + 1; j < n; j++)
        {
            auto it = visited.find(-nums[i] - nums[j]);
            if (it != visited.end())
            {
                vector<int> add = {nums[i], nums[j], -nums[i] - nums[j]};
                sort(add.begin(), add.end());
                result.insert(add);
            }

            visited.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(result.begin(), result.end());
    return ans;
}

// alternate more optimal solution
// derived from the sorting solution from 2 sum
// time = O(N2), space = O(no. of triplets)
vector<vector<int>> threeSum2(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1, right = n - 1;
        while (left < right)
        {
            if ((nums[left] + nums[right]) == -nums[i])
            {
                result.push_back({nums[i], nums[left], nums[right]});
                right--;
                left++;
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if ((nums[left] + nums[right]) > -nums[i])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }

    return result;
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

    vector<vector<int>> out = threeSum2(nums);

    for (int i = 0; i < out.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}