#include<bits/stdc++.h>
using namespace std;

int gcd1(int x1, int x2){

    int gcd =1;
    for (int i = 2; i <= min(x1,x2); i++)
    {
        if (x1%i==0 && x2%i==0)
        {
            gcd=i;
        }
        
    }
    return gcd;
    
}

int gcd2(int x1, int x2){

    
    while (x1*x2!=0)
    {
        int m =min(x1,x2);
        x2= max(x1,x2) % m;
        x1=m;
    }
    
    return x1+x2;

    
}
 
int main() {
    int n1,n2;
    cin >> n1 >> n2 ;
    if(n1<0 || n2<0) cout << "Invalid";
    else cout << gcd2(n1,n2);
    return 0;
}
