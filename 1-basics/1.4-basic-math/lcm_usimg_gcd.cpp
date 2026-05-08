#include<bits/stdc++.h>
using namespace std;

int lcm_using_gcd(int y1, int y2){
    int x1=y1,x2=y2;
    while (x1*x2!=0)
    {
        int m =min(x1,x2);
        x2= max(x1,x2) % m;
        x1=m;
    }
    
    return (y1*y2)/(x1+x2);
}


int main() {
    int n1,n2;
    cin >> n1 >> n2;
    if(n1<0 || n2<0) cout << "Invalid";
    else cout << lcm_using_gcd(n1,n2);
    return 0;
}