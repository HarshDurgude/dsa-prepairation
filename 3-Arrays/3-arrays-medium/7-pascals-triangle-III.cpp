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

// approach
// this approach basically goes with the defination of the pascals triangle
// an element(triangle[r][c]) is the sum of triangle[r-1][c] + triangle[r-1][c-1]

#include <bits/stdc++.h>
using namespace std;

// initial approach, also optimal
vector<vector<int>> pascalTriangleIII(int n)
{
    vector<vector<int>> triangle(n);
    triangle[0] = {1};

    for (int i = 1; i < n; i++)
    {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
    }
    return triangle;
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