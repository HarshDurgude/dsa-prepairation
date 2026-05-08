#include<bits/stdc++.h>
using namespace std;
int c=1,sum=0;
void n_times_1(int n){
    if (c ==n)
    {
        return;
    }
    cout << 1 << endl;
    c++;
    n_times_1(n);
    
}
void n_times_name(int n){
    if (c ==n)
    {
        return;
    }
    cout << "Harsh" << endl;
    c++;
    n_times_name(n);
    
}
void oneToN(int n){
    if (c ==n+1)
    {
        return;
    }
    cout << c << endl;
    c++;
    oneToN(n);
    
}
void nToOne(int n){
    if (n==0)
    {
        return;
    }
    cout << n << endl;
    n--;
    nToOne(n);
    
}

int sumOfFirstN(int n){
    if(n==0) return 0;
    return n+sumOfFirstN(n-1);
}

int factorial(int n){
    if(n==0) return 1;
    return n*sumOfFirstN(n-1);
}

int main() {
    int x;
    if(x<0) cout << "Invalid";
    else cout <<factorial(x);
    return 0;
}