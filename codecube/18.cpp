#include <bits/stdc++.h>

using namespace std;
int mx = -2e9, mn = 2e9;
int main(){
    int n; cin>>n;
    while(n--){
        int a; cin>>a;
        mx = max(a,mx);
        mn = min(a,mn);
    }
    cout<<mx<<'\n'<<mn<<'\n';
    return 0;
}