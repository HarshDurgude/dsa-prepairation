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
// making an hash array
// assigning every element as 0
// looping throgh the input arr with i
// increamenting the element of hash arr everytime
// that occurs in input arr


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

    // initial aproach
    // int hash[13]={0};
    // for (int i = 0; i < 13; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == arr[j])
    //         {
    //             hash[i]++;
    //         } 
    //     }
    // }

    // Better approach
    int hash[13]={0}; 
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    
    // int hash[13]={0}; 
    // assigns evry element of array to 0,
    // if outside main 'int hash[13];'
    // enough for every elemnt 0

    // Array Size inside main :
    // Stack memory is limited (~1–8MB)
    // Large arrays inside functions → stack overflow
    // Heap (vector/new) → safest for large data
    // eg.(insdie main) int hash[10^7] ❌
    // ≤ 10⁶ → safe in main
    // >10⁶ → prefer heap (vector)

    // Querry
    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;
        // logic to check frequency
        cout <<"Frequency of ("<<num <<") :" <<  hash[num] << endl;
    }
    return 0;
}