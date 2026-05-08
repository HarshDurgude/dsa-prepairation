#include<bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of N integers, 
// write a program to implement the Bubble Sorting algorithm.

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
// sequentially compare two adjecent elements and swap
// if req to make large number to later position 
// doing this sequentially will push largest element to end
// and again make two parts, sorted(at end) and unsored(at start)
// continuing this will increase the sorted part and finally one 
// element will be in unsorted and we can add swaped flag to
// break, if arr becomes sorted early

// complexity
// time wrost,avg = O(n^2), best = O(n), space O(1)

// initial approach (worked) : swaps counter  
// added later for furthur optimization
void bubble_sort(vector<int> &arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        bool swaped=false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swaped=true;
            }
            
        }
        if (swaped==false)
        {
            break;
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
    
    bubble_sort(arr, n);
    return 0;
}