#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};

    v.push_back(4);   // add element
    v.pop_back();     // remove last element

    for (int x : v) {
        cout << x << " ";
    }
}