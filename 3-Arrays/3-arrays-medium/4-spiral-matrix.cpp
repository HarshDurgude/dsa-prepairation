// Given an M * N matrix, print the elements in a clockwise spiral manner.
// Return an array with the elements in the order of their appearance when
// printed in a spiral manner.

// input
// 4 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

// output
// 9
// 5
// 6
// 7
// 11
// 10

// approach
// so we observe the pattern that the spiral will be repeatation of smaller and smaller
// squares so we can use 4 for loops for each side of smaller squares to get each element
// but then the last square will sometimes have 1/2/3/4 sides so we add conditions to check that
// the conditions also check for edge cases like vertical(m,1) and horizontal(1,n) matrix

// revision
// missed the edge cases for vertical(m,1) and horizontal(1,n) matrix
// adding extra conditions to 2 of the 4 for loops, but then figured
// out the solution on my own without looking at the code

#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int top = 0, left = 0;
    int bottom = matrix.size() - 1, right = matrix[0].size() - 1;

    vector<int> spiral;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            spiral.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            spiral.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                spiral.push_back(matrix[bottom][i]);
            }
        }
        bottom--;

        if (left <= right)
        {

            for (int i = bottom; i >= top; i--)
            {
                spiral.push_back(matrix[i][left]);
            }
        }
        left++;
    }
    return spiral;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> nums[i][j];
        }
    }
    vector<int> output = spiralOrder(nums);

    for (int out : output)
    {
        cout << out << endl;
    }

    return 0;
}