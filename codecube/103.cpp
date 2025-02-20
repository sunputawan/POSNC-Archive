#include <bits/stdc++.h>

using namespace std;
int s[1000005];
int main(){
    int n,p; cin>>n>>p;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        s[a]++; s[b+1]--;
    }

    for(int i=1;i<=1000000;i++){
        s[i] += s[i-1];
    }
    bool found = false;
    for(int i=p;i<=1000000;i++){
        if(s[i]==n){
            cout<<i-p<<'\n';
            return 0;
        }
    }
    for(int i=p;i>=0;i--){
        if(s[i]==n){
            cout<<p-i<<'\n';
            return 0;
        }
    }

    cout<<-1<<'\n';
    return 0;
}