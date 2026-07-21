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
// logic is very straight forword onec u know the hidden relation betn
// nCr and pascals triangle, in pascals triangle for rth row and cth column
// and while calculating nCr = n! / (r! * (n-r)!) we can just do
// = [(n)*(n-1)*(n-2)...(n-r+1)] / [1*2*3...r]

#include <bits/stdc++.h>
using namespace std;

// intial approach, worked but
// was lil bit complex so simplified using 1 for loop
int pascalTriangleI(int r, int c)
{

    r = r - 1;
    c = c - 1;

    if (c > r - c) // lowering iterations cause nCr and (n)C(n-r) are same
        c = r - c;

    int result = 1;

    for (int i = 1; i <= c; i++)
    {
        result *= (r - c + i);
        result /= i;
    }
    return result;
}

int main()
{

    int r, c;
    cin >> r >> c;

    cout << pascalTriangleI(r, c);
    return 0;
}