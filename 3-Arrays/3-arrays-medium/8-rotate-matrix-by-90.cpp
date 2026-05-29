// Problem Statement : Given an N * N 2D integer matrix, rotate the matrix by 90
// degrees clockwise.
// The rotation must be done in place, meaning the input 2D matrix must be
// modified directly.

// input
// 5
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25

// output
// 21 16 11 6 1
// 22 17 12 7 2
// 23 18 13 8 3
// 24 19 14 9 4
// 25 20 15 10 5

// approach
// so there is hidden pattern or a trick as we need to do this in place we cant directly
// swap elements so we reverse each rows first then swapping matrix[i][j] with
// matrix[N - 1 - j][N - 1 - i] or we can also simplify it by swapping first matrix[i][j]
// with matrix[j][i] and then reversing each row
#include <bits/stdc++.h>
using namespace std;

// intial approach, derived aproach with a hint
void rotateMatrix(vector<vector<int>> &nums)
{
    int N = nums.size();

    for (int i = 0; i < N; i++)
    {
        reverse(nums[i].begin(), nums[i].end());
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            swap(nums[i][j], nums[N - 1 - j][N - 1 - i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cin >> nums[i][j];
        }
    }
    rotateMatrix(nums);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}