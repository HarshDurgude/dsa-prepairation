#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of N integers,
// write a program to implement the Selection sorting algorithm.

// input
// 5
// 3 5 6 2 1

// output
// 1
// 2
// 3
// 5
// 6

// approach
// we can sort the array by selecting the min element
// and then swapping it with the first to get a sorted and unsorted part
// then continuing finding the min element and swapping it with first
// of the unsorted part, one element remaining in unsorted part will be
// auto sorted

// complexity
// time O(n^2), space O(1)

void selection_sort(vector<int> &arr, int n)
{

    // alternate approach (rejected) :
    // too many swap func usage
    // for (int i = 0; i < n-1; i++)
    // {
    //     for (int j = i +1; j < n; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             swap(arr[j],arr[i]);
    //         }
    //     }
    // }

    // Initial approach (optimal)
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    // printing sorted aray
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    selection_sort(arr, n);
    return 0;
}