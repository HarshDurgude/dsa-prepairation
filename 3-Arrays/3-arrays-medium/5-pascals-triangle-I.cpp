// Problem Statement : Given two integers r and c, return the value at the rth row and
// cth column (1-indexed) in a Pascal's Triangle.
// In Pascal's triangle:
// - The first row contains a single element 1.
// - Each row has one more element than the previous row.
// - Every row starts and ends with 1.
// For all interior elements (i.e., not at the ends), the value at position (r, c) is
// computed as the sum of the two elements directly above it from the previous row:
// Pascal[r][c]=Pascal[r−1][c−1]+Pascal[r−1][c]
// where indexing is 1-based

// input
// 4 2

// output
// 3

// approach
// logic is very straight forword once u know the hidden relation betn
// nCr and pascals triangle, in pascals triangle for rth
// row and cth column(0-indexed) (row)C(col) is the formula
// and while calculating nCr = n! / (r! * (n-r)!) we can just do
// = [(n)*(n-1)*(n-2)...(n-(r-1))] / [1*2*3...r]

#include <bits/stdc++.h>
using namespace std;

// intial approach, worked but
// was lil bit complex so simplified using 1 for loop

int pascalTriangleI(int row, int col)
{

    int n = row - 1, r = col - 1, ncr = 1;

    r = min(r, n - r);

    for (int i = 0; i < r; i++)
    {
        ncr = ((ncr * (n - i)) / (i + 1));
    }
    return ncr;
}

int main()
{

    int r, c;
    cin >> r >> c;

    cout << pascalTriangleI(r, c);
    return 0;
}