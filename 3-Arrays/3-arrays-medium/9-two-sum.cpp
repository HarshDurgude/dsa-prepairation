// Problem Statement : Given an array of integers nums and an integer target. Return
// the indices(0 - indexed) of two elements in nums such that they add up to target.
// Each input will have exactly one solution, and the same element cannot be used
// twice. Return the answer in any order.

// input
// 5
// 1 6 2 10 3
// 7

// output
// 0
// 1

// approach
// we traverse throgh the vector but also create a hashap parallelly which stores the
// target - current wih current's index, so if we find a current in furthur traversal
// that is eqaul to our stored elements in the hashmap then we return both of their indexes

#include <bits/stdc++.h>
using namespace std;

// optimal solution
vector<int> twoSum1(vector<int> &nums, int target)
{
    unordered_map<int, int> visited;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = visited.find(target - nums[i]);
        if (it != visited.end())
        {
            return {it->second, i};
        }
        else
        {
            visited[nums[i]] = i;
        }
    }
    return {};
}

// alternate solution, when we are not allowed to use map
vector<int> twoSum2(vector<int> &nums, int target)
{
    // Size of the nums vector
    int n = nums.size();

    // Vector to store indices of two numbers
    vector<int> ans;

    vector<vector<int>> eleIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        eleIndex.push_back({nums[i], i});
    }

    // Sort by first element in ascending order
    sort(eleIndex.begin(), eleIndex.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; }); // this is like the lambda functon

    /* Two pointers: one starting
    from left and one from right*/
    int left = 0, right = n - 1;

    while (left < right)
    {
        /* Calculate sum of elements
        at left and right pointers*/
        int sum = eleIndex[left][0] + eleIndex[right][0];

        if (sum == target)
        {

            /* If sum equals target,
            store indices and return*/
            ans.push_back(eleIndex[left][1]);
            ans.push_back(eleIndex[right][1]);
            return ans;
        }
        else if (sum < target)
        {

            /* If sum is less than target,
            move left pointer to the right*/
            left++;
        }
        else
        {

            /* If sum is greater than target,
            move right pointer to the left*/
            right--;
        }
    }

    // If no such pair found, return {-1, -1}
    return {-1, -1};
}

int main()
{
    vector<int> nums;
    int n, target;
    cin >> n;
    nums.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cin >> target;

    vector<int> out = twoSum1(nums, target);
    cout << out[0] << endl;
    cout << out[1];

    return 0;
}