#include<bits/stdc++.h>
using namespace std;

bool checkArmstrong(int x){
    int num=0,origanal=x;
    int noOfDigits = (x == 0) ? 1 : int(log10(x) + 1);
    while(x>0){
        num = num + pow((x%10),noOfDigits);
        x= x/10;
    }
    if (num == origanal)
    {
        return true;
    }else{
        return false;
    }
    
    
}
 
int main() {
    int n;
    cin >> n ;
    cout << checkArmstrong(n);
    return 0;
}

// fix negavtive number cases and using log insted pow()