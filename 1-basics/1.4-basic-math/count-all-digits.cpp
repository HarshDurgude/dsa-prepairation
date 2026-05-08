#include<bits/stdc++.h>
using namespace std;

int main() {
    int inp;
    cin >> inp;
    int num=inp, count=0;
    while (num>0)
    {
        cout << num % 10 << endl;
        count++;
        num = num/10;
    }
    cout << "No. of digits : "<< count;
    
    return 0;
}

// fails for the negative number, and zero