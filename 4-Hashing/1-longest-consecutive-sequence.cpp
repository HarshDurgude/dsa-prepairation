// Problem Statement : Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers. The
// integers in this sequence can appear in any order.

// input
// 10
// 100 4 200 1 3 2 201 202 203 204

// output
// 5

// approach
// converting given vector to a unordered set which takes O(n), then traversing that
// set and when we find an element whose adjecent smaller element doesnt exist
// so that we always start from the smallest of an sequence then we start
// counting the consecutive from that by doing ++ and increamenting local count for
// that perticular seq and after that seq is over, we change globalCnt if it is
// smaller than local count and in end we retrun globalCnt

// hint 1
// convert whole vector to unordered set

// hint 2
// traverse the set and only start counting seq if current
// is the smallest of the seq, check by checking if current-1 exist, if not
// then current is smallest of that seq

#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }

    unordered_set<int> nums_set;
    int globalCnt = 1;
    for (int i = 0; i < n; i++)
    {
        nums_set.insert(nums[i]);
    }

    for (int it : nums_set)
    {

        if (nums_set.find(it - 1) == nums_set.end())
        {
            int x = it;
            int cnt = 1;
            while (nums_set.find(x + 1) != nums_set.end())
            {
                cnt++;
                x++;
            }
            globalCnt = max(globalCnt, cnt);
        }
    }

    return globalCnt;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    cout << longestConsecutive(nums);

    return 0;
}
