// Problem Statement : Given an integer n, return the first n (1-Indexed) rows of Pascal's triangle.
// In Pascal's triangle:
// - The first row has one element with a value of 1.
// - Each row has one more element in it than its previous row.
// - The value of each element is equal to the sum of the elements directly above it when
// arranged in a triangle format.

// inp
// 5

// output
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1

// approach 1
// this approach basically goes with the defination of the pascals triangle
// an element(triangle[r][c]) is the sum of triangle[r-1][c] + triangle[r-1][c-1]

// approach 2
// we can also solve this by genrating rows like we did in pascals triangle 2
// but that approach is best fitted for genrating only a row, here we already
// know the prev rows so adding of two elements from prev row is more simpler

#include <bits/stdc++.h>
using namespace std;

// initial approach, also optimal
vector<vector<int>> pascalTriangleIII(int n)
{
    vector<vector<int>> rows;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                row.push_back(1);
            }
            else
            {
                row.push_back(rows[i - 1][j - 1] + rows[i - 1][j]);
            }
        }
        rows.push_back(row);
    }
    return rows;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> triangle = pascalTriangleIII(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}