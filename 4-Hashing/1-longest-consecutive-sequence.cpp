#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int longSeq = 1, globalLongSeq = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] + 1 == nums[i])
        {
            longSeq++;
            globalLongSeq = max(longSeq, globalLongSeq);
        }
        else if (nums[i - 1] == nums[i])
        {
            continue;
        }
        else
        {
            longSeq = 1;
        }
    }
    return globalLongSeq;
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
