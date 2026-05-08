#include<bits/stdc++.h>
using namespace std;

// Given an array of integers: [1, 2, 1, 3, 2] 
// and we are given some queries: [1, 3, 4, 2, 10]. 
// For each query, we need to find out how many times 
// the number appears in the array. 
// For example, if the query is 1 our answer would be 2, 
// and if the query is 4 the answer will be 0. 

// Input 
// 5
// 1 3 2 1 3  
// 5
// 1 4 2 3 12

// Ouitput 
// Frequency of (1) :2
// Frequency of (4) :0
// Frequency of (2) :1
// Frequency of (3) :2
// Frequency of (12) :0

// solution
// same as before just using maps

int main() {

    // Input
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;
    }

    // initial approach
    int maxFreq = 0, minFreq = n;
    int maxEle = 0, minEle = 0;

    for (auto x : mpp) {
        int element = x.first;
        int count = x.second;

        // Update max frequency element
        if (count > maxFreq) {
            maxFreq = count;
            maxEle = element;
        }

        // Update min frequency element
        if (count < minFreq) {
            minFreq = count;
            minEle = element;
        }

    }
    cout << "max : "<< maxEle << " : "<< maxFreq << " times" << endl;
    cout << "min : "<< minEle << " : "<< minFreq << " times";
    return 0;
} 