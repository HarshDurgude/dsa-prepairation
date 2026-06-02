// Problem Statement : Given an integer array nums of size n. Return all
// elements which appear more than n/3 times in the array. The output can
// be returned in any order. array can even have no majority element.

// input
// 7
// 1 2 1 1 3 2 2

// output
// 1 2

// approach
// kind of intuative approach when u have understood the majority element - I really
// well, so the trick is that w can have at max 2 elements that appear more than n/3
// times (0,1,2 elements to be precise) so just like we used repeated canceling in
// majority element - I, we can keep two vars (can1,can2) and when iterating when
// we find known element then we increament its counter, if its not known then we replace
// a candidate whose counter is zero and make its counter 1 if both are non-zero then
// decreament both the counters, so according to obeservation the one who appears more
// n/3 times will definetly survive after this then we check again with a for loop to
// who actually appears more than n/3 times from the survivers

// complexity
// time = O(N) + O(N) = O(N), space = O(1)

#include <bits/stdc++.h>
using namespace std;

// optimal solution
vector<int> majorityElementTwo(vector<int> &nums)
{
    int n = nums.size();
    int ele1 = INT_MIN, ele2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            if (cnt1 == 0)
            {
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                ele2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == ele1)
        {
            cnt1++;
        }
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
    }
    if (cnt1 > n / 3)
    {
        ans.push_back(ele1);
    }
    if (cnt2 > n / 3)
    {
        ans.push_back(ele2);
    }
    return ans;
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

    vector<int> out = majorityElementTwo(nums);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}