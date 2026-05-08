#include<bits/stdc++.h>
using namespace std;


// handle for negative
vector<int> getAllDivisors(int x){
    vector<int> divisors;

    int limit = sqrt(x);

    for (int i = 1; i <= limit; i++)
    {
        if (x % i == 0)
        {
            divisors.push_back(i);

            if(i != x/i)
                divisors.push_back(x/i);
        }
    }

    return divisors;
}

int main() {
    int n;
    cin >> n;

    vector<int> ans = getAllDivisors(n);
    sort(ans.begin(), ans.end());
    for(int d : ans){
        cout << d << " ";
    }

    return 0;
}