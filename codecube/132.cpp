#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    long long a = 1;
    for(int i=1;i<=n;i++){
        a *= 4;
    }
    cout<<a<<'\n';
}