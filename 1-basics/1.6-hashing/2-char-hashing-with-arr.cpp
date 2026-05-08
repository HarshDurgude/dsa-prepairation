#include<bits/stdc++.h>
using namespace std;

// problem : same like number hashing but for chars(a-z)

// input
// abcdabehf
// 5
// a
// g
// h
// b
// c

// output
// Frequency of (a) : 2
// Frequency of (g) : 0
// Frequency of (h) : 1
// Frequency of (b) : 2
// Frequency of (c) : 1

// solution
// making arr of lengh 26 
// (lowercaseletter) - 'a' --> serial number 
// of that letter in alphabets 
// because of ascii (lowercaseletter) and 'a' 
// both are considered int in this calc 

int main() {
    string str;
    cin >> str;

    // Precompute
    int hash[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        hash[str[i] - 'a']++;
    }
    // ascii
    // a=97, 'c' - 'a' = 2, 'e' - 'a' = 4

    // for handling every character(256) 
    // int hash[256]={0}; hash[str[i]]++; cout<<hash[ch];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >>  ch;
        // logic to check frequency
        cout << "Frequency of ("<<ch<<") : "<<hash[ch-'a']<<endl;

    }
    
    return 0;
}