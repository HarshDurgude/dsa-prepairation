// #include<bits/stdc++.h>
// using namespace std;
// int front=0,rare;

#include <bits/stdc++.h>
using namespace std;

bool palindrome_check(string str, int front, int rear) {
   
    if (front >= rear)
        return true;

    if (str[front] != str[rear])
        return false;

    return palindrome_check(str, front + 1, rear - 1);
}

int main() {
    string str;
    cin >> str;

    if (palindrome_check(str, 0, str.size() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}






// bool palindrome_check(string str,int &front, int &rare){
//     if(rare <= front){
//         return true;
//     }
//     if (str[front] != str[rare])
//     {
//         return false;
//     }
    
//     front++;
//     rare--;
//     return palindrome_check(str);

// }

// int main() {
//     int n=3;
//     string str ="aba";
//     rare=n-1;
//     cout << palindrome_check(str);
    
    
//     return 0;
// }



