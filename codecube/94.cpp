#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            cout<<"Wrong Answer\n";
            return 0;
        }
    }

    cout<<"Accepted\n";
    return 0;
}