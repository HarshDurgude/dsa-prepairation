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
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Precompute

    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // MAP (ordered map) :
    // - key value pair kind of array
    // - Stores keys in sorted order
    // - Time: insert/search/delete = O(log n)
    // - Allows complex keys (e.g., pair, custom types with comparator)

    // UNORDERED_MAP (hash map)
    // - Implemented using Hash Table and chaining and collision
    // - No ordering of keys (random order)
    // - Avg Time: O(1), Worst(very rare) Time: O(n) [due to collisions]
    // - Faster than map in most practical cases
    // - complex data structures ❌ (eg. unordered_map<pair<int, int>, int> ❌)

    // Querry
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        // logic to check frequency
        cout <<"Frequency of ("<<num <<") :" <<  mpp[num] << endl;
    }
    return 0;
}