#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char a[100];
    cout<<"Enter string : "; cin>>a;
    int n = strlen(a);
    bool is_palindrome = true;
    for(int i=0;i<n/2;i++){
        if(a[i]!=a[n-1-i]){ is_palindrome = false; break;}
    }

    if(is_palindrome)
        cout<<"It's palindrome!";
    else
        cout<<"It's not palindrome!";
}
