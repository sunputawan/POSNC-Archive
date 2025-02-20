#include <bits/stdc++.h>

using namespace std;
string x;
bool isPalindrome(int s,int t){
    int i = s;
    int j = t;
    while(i<j){
        if(x[i++]!=x[j--]){
            return false;
        }
    }
    return true;
}
int main(){
    cin>>x;
    for(auto &c:x){
        if(c>='a')
            c-=32;
    }
    int n = x.size();
    if(isPalindrome(0,n-1)){
        if(isPalindrome(0,n/2-1)&&isPalindrome((n+1)/2,n-1)){
            cout<<"Double Palindrome\n";
        }
        else
            cout<<"Palindrome\n";
    }
    else
        cout<<"No";
}
