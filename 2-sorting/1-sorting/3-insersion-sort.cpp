#include<bits/stdc++.h>
using namespace std;

// Problem Statement: insersion sort

// input 
// 5
// 3 9 6 2 1 

// output 
// 1
// 2
// 3
// 6
// 9

// Approach
// instead of sorting the entire array at a time
// starting from the initial elements and then 
// sorting first 2 elements then considering the 3rd 
// and like this incresing number of elements and inserting that 
// new elemnet at its exact position with repeated swaping untill 
// its at the right position

// complexity
// time best = O(n), wrost,avg = O(n^2), space = O(1)

// initial approach : complexity already optimal
void insersion_sort_1(vector<int> &arr, int n){

    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j-1] > arr[j])
            {
                swap(arr[j], arr[j-1]);
            }
            else
            {
                break;
            }
            
        }        
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

// alternate aproach (more clean)
void insersion_sort_2(vector<int> &arr, int n){

    for (int i = 1; i < n; i++)
    {
        int j=i;
        while (j>0 && arr[j-1] > arr[j])
        {
            swap(arr[j], arr[j-1]);
            j--;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}


int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    insersion_sort_1(arr, n);
    return 0;
}