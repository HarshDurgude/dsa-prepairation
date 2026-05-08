#include<bits/stdc++.h>
using namespace std;

// optimised and efficient approach
bool checkPalindrome1(int x){
    // Edge cases
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversedHalf = 0;

    // Reverse only half of the number
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10; 
    }

    // For even digits: x == reversedHalf
    // For odd digits: x == reversedHalf / 10 (middle digit ignored)
    return (x == reversedHalf || x == reversedHalf / 10);
}



// simple aproach
bool checkPalindrome2(int n) {
    int revNum = 0; // Initialize a variable to store the reverse of the number
    int dup = n; // Create a duplicate variable to store the original number

    // Iterate through each digit of the number until it becomes 0
    while (n > 0) {
        int ld = n % 10; // Extract the last digit of the number
        revNum = (revNum * 10) + ld; // Build the reverse number by appending the last digit
        n = n / 10; // Remove the last digit from the original number
    }

    // Check if the original number is equal to its reverse
    if (dup == revNum) {
        return true; // If equal, return true indicating it's a palindrome
    } else {
        return false; // If not equal, return false indicating it's not a palindrome
    }
}





int main() {
    int n;
    cin >> n;
    cout << checkPalindrome2(n);
}


// fix for negative numbers