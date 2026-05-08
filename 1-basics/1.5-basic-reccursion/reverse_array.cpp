#include<bits/stdc++.h>
using namespace std;
int front=0,rare;

void reverse_arr(int arr[]){
    if(rare <= front){
        return;
    }
    int temp =arr[front];
    arr[front]=arr[rare];
    arr[rare]=temp;
    front++;
    rare--;
    reverse_arr(arr);

}

int main() {
    int n=5;
    // int arr[n]={1,3,5,4,2};
    int arr[n];
    for (int i = 0; i < 5; i++)
    {
        cin>>arr[i];
    }
    
    rare=n-1;
    reverse_arr(arr);
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    
    return 0;
}



