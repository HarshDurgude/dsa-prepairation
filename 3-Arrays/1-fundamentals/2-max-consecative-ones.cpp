#include<bits/stdc++.h>
using namespace std;

// problem statement : Given a binary array nums, return 
// the maximum number of consecutive 1s in the array.

// inputs 
// 5
// 1 1 1 0 1  

// output
// 3

// approach
// iterate through the array, keep a counter 
// and count ones but reset it when found 0
// and also keep a counter to store max of the counts

// initial approach (worked) but,
// missed maxi which keeps track of max occurances
int maxConsOnes(vector<int> &arr){
    int count=0,maxi=0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            count++;
            maxi= max(count, maxi);
        }else
        {
            count=0;
        }
        
        
    }
    return maxi;
}
int main() {
    vector<int> arr;
    int n;
    cin >> n;
    arr.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << maxConsOnes(arr);

    return 0;
}