#include<bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    unordered_set<int> seen;

    while (n != 1) {
        if (seen.count(n)) return false; // loop detected (NOT happy)
        seen.insert(n);

        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;
    }

    return true;
}

int main() {
    int x;
    cin >> x;
    if(x<0) cout << "Invalid";
    else cout << isHappy(x);
    return 0;
}