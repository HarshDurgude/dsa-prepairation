#include<bits/stdc++.h>
using namespace std;

void pat2(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout << "* ";
        }
        cout << endl;
    }
    
}
void pat3(int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout << j+1 << " ";
        }
        cout << endl;
    }
    
}
void pat4(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            /* code */
            cout << i << " ";
        }
        cout << endl;
    }
    
}
void pat5(int n){
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            
            cout << "* ";
        }
        cout << endl;
    }
    
}
void pat7(int n){
    int r = n*2 -1;
    // spaces for each row = n-1
    // stars  for each row = i*2 - 1
    for (int i = 1; i<=n; i++)
    {

        for (int j = 1; j <= n-i; j++)
        {
            
            cout << "  ";
        }
        for (int j = 1; j <= i*2 - 1; j++)
        {
            
            cout << "* ";
        }
        cout << endl;
    }
    
}
void pat8(int n){
    int r = n*2 -1;
    // spaces for each row = i
    // stars  for each row = (n-i)*2 -1 
    for (int i = 0; i<n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            
            cout << "  ";
        }
        for (int j = 1; j <= (n-i)*2 -1; j++)
        {
            
            cout << "* ";
        }
        cout << endl;
    }
    
}
void pat10(int n){
    int r = n*2 -1;
    // spaces for each row = i
    // stars  for each row = (n-i)*2 -1 
    for (int i = 0; i<2*n-1; i++)
    {

        for (int j = 0; j < i; j++)
        {
            
            cout << "* ";
        }
        for (int j = 1; j <= (n-i)*2 -1; j++)
        {
            
            cout << "* ";
        }
        cout << endl;
    }
    
}
void pat11(int n){
    bool p =1;
    for (int i = 0; i < n; i++)
    {
        bool flag =p;
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout << flag << " ";
            flag=!flag;
        }
        p=!p;
        cout << endl;
    }
    
}
void pat12(int n){
    int r = n*2 -1;
    // spaces for each row = i
    // stars  for each row = (n-i)*2 -1 
    for (int i = 1; i<=n; i++)
    {

        for (int j = 0; j < i; j++)
        {
            
            cout << j+1;
        }
        for (int j = 0; j < (n-i)*2; j++)
        {
            
            cout << " ";
        }
        for (int j = i; j > 0; j--)
        {
            
            cout << j;
        }
        cout << endl;
    }
    
}
void pat13(int n){
    int p = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            /* code */
            cout << p << " ";
            p++;
        }
        cout << endl;
    }
    
}
void pat14(int n){
    
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            /* code */
            cout << ch<< " ";
            
        }
        cout << endl;
    }
    
}
void pat15(int n){
    
    for (int i = n-1; i >= 0; i--)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            /* code */
            cout << ch<< " ";
            
        }
        cout << endl;
    }
    
}
void pat17(int n){
    
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j=1; j<=n-i; j++)
        {
            /* code */
            cout << " ";
            
        }
        for (char ch = 'A'; ch <= 'A' + i-1; ch++)
        {
            /* code */
            cout << ch;
            
        }
        for (char ch = 'A' + i-2; ch >= 'A'; ch--)
        {
            /* code */
            cout << ch;
            
        }
        
        cout << endl;
    }
    
}
void pat18(int n){
    
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A' + n-i; j <= 'A' + n-1 ; j++)
        {
            cout << j;
        }
        
        cout << endl;
    }
    
}
void pat19(int n){
    int spaces =0;
    for (int i = 1; i <= 2*n; i++)
    {
        for (int j = 0; j < n-spaces ; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <  spaces*2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n-spaces ; j++)
        {
            cout << "*";
        }
        if (i<n) spaces++;
        else if (i >n) spaces--;
        cout << endl;
        
    }
    
}
void pat20_1(int n){
    for (int i = 1; i <= 2*n; i++)
    {
        for (int j = 0; j < n- (abs(n-i)) ; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <  abs((n-i))*2; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n- (abs(n-i)) ; j++)
        {
            cout << "*";
        }

        cout << endl;
        
    }
    
}
void pat20_2(int n){
    int stars =1;
    for (int i = 1; i <= 2*n; i++)
    {
        int spaces = (n-stars)*2;
        for (int j = 0; j < stars; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <  spaces; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < stars ; j++)
        {
            cout << "*";
        }
        if(i<n) stars++;
        else stars--;

        cout << endl;
        
    }
    
}
void pat21(int n){
    int x,y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(i == 1 || j == 1 || i == n || j == n) cout << "* ";
            else cout << "  ";
        }
        cout << endl;
        
    }
    
}
void pat22(int n){
    int x,y;
    for (int i = 1; i <= (n*2)-1; i++)
    {
        for (int j = 1; j <= (n*2)-1; j++)
        {
            int top =i;
            int left =j;
            int right = (2*n) - j;
            int down = (2*n) - i;
            int p = min(min(right,left), min(top,down));
            cout << n-p+1;
        }
        cout << endl;
        
    }
    
}
int main() {
    int n;
    cin >> n;
    pat22(n);
    return 0;
} 