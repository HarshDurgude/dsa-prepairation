// Problem Statement : Given an m x n integer matrix matrix,
// if an element is 0, set its entire row and column to 0.
//  You must do it in place.

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

// hint 1
// we check the elements from right to left for assending order
// and where it breaks the order thats where we find the pivot

// hint 2
// then find the
// element just bigger than that then we swap them and reverse the assending to make it
// dessending to get just bigger number than that

#include <bits/stdc++.h>
using namespace std;

// optimal approach
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();    // Number of rows
    int n = matrix[0].size(); // Number of columns

    bool firstRowZero = false;
    bool firstColZero = false;

    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    // n -> vertical, m -> horizontal
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> nums[i][j];
        }
    }
    setZeroes(nums);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}