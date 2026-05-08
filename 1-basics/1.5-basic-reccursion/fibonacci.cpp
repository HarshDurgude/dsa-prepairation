#include<bits/stdc++.h>
using namespace std;
int x1=0,x2=1,c=0;
void print_fibonacci(int x){
    if (c==x)
    {
        /* code */
        return;
    }

    cout <<x2;
    int temp=x2;
    x2=x2+x1;
    x1=temp;
    c++;
    print_fibonacci(x);
}

int fibonacci(int x){

    if(x<=1) return x;
    return fibonacci(x-2)+ fibonacci(x-1);
}


long long fib(long long n){
    if(n<=1) return n;
    long long a=0,b=1,c;
    for(long long i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}


int main() {
    int n;
    cin >> n;
    // for (int i = 0; i <= n; i++)
    // {
    //     cout << fibonacci(i) << endl;
    // }
    // print_fibonacci(n);
    fib(n);
    

    return 0;
}