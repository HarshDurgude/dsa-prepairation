// Problem Statement : Given an integer r, return all the values in the
// rth row (1-indexed) in Pascal's Triangle in correct order.
// In Pascal's triangle:
// - The first row has one element with a value of 1.
// - Each row has one more element in it than its previous row.
// - The value of each element is equal to the sum of the elements directly above it when arranged in a triangle format.

// input
// 5

// output
// 1
// 4
// 6
// 4
// 1

// approach
// first the initial approach comes to mind seems optimal too beacasue we
// are miroring elemnets instead of genrating every element, but its not
// optimal, think like the pattern that forms in that percular row from
// starting elements and with each increasing column number something is
// multiplied and somethiing is devided for each iteration

#include <bits/stdc++.h>
using namespace std;

// intial approach, worked but not optimal
// int nCr(int n, int r)
// {
//     if (r > n - r) // lowering iterations cause nCr and (n)C(n-r) are same
//         r = n - r;
//     int ans = 1;
//     for (int i = 1; i <= r; i++)
//     {
//         ans *= (n - r + i);
//         ans /= i;
//     }
//     return ans;
// }
// vector<int> pasacalTriangleII(int r)
// {
//     vector<int> result(r);
//     for (int i = 0; i < (r + 1) / 2; i++)
//     {
//         result[i] = result[r - i - 1] = nCr(r - 1, i);
//     }
//     return result;
// }

// optimal approach
vector<int> pascalTriangleII(int r)
{
    vector<int> result(r);

    result[0] = 1;
    for (int i = 1; i < r; i++)
    {
        result[i] = (result[i - 1] * (r - i)) / i;
    }
    return result;
}

int main()
{
    int r;
    cin >> r;

    vector<int> out = pascalTriangleII(r);

    for (int i = 0; i < out.size(); i++)
    {
        cout << out[i] << endl;
    }

    return 0;
}