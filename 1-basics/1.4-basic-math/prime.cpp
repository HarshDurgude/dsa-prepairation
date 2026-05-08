#include<bits/stdc++.h>
using namespace std;

bool isprime(int x){
    int count=0;
    for (int i = 1; i*i <= x; i++)
    {
        if (x%i == 0)
        {
            count++;
            if (x / i != i) {
                count++;
            }
        }
        if(count>2) break;
        
    }
    if (count==2)
    {
        return true;
    }else
    {
        return false;    }
    
    

    
}

int main() {
    int n;
    cin >> n;

    cout << isprime(n);

    return 0;
}