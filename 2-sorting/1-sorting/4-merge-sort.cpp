#include<bits/stdc++.h>
using namespace std;

// Problem Statement: merge sort

// input 
// 7
// 5 4 9 2 3 1 8

// output 
// 1
// 2
// 3
// 4
// 5
// 8
// 9


// Approach
// we have to use 2 funcs merge and mergesort 
// mergesort will call itself recursively 2 times 
// on the two roughly equal parts of the arrays
// then merge func will be called to merge the divided arrays
// we didvide till only one element as that will be sorted 
// we dont slice or create subarrays we keep the indexes of
// subarray start,end in memory and pass that furthur
// we create temp array in merge to store the merged and at the
// end of merge we combine that temp to main array
 
// complexity
// space =O(n)
// time = O(N*Log2(N))

// optimal approach
void merge(vector<int> &arr, int low,int mid, int high){
    int i=low,j=mid+1;
    vector<int> temp;
    while ((i<mid+1) && j<high+1)
    {
        if (arr[i] <= arr[j])
        {  
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]); 
            j++;
        }
        
    }
    // adding remaining elements on either side directly
    while (i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i]= temp[i-low];
    }
    
    
}

void merge_sort(vector<int> &arr, int low, int high){
    if (low >=high) return;
    
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);

    merge(arr,low, mid, high);

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
    
    merge_sort(arr,0,n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}