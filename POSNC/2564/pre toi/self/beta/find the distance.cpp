#include <bits/stdc++.h>

using namespace std;
int main(){
    long long k,n,s=0;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        s += (n>>i);
    }
    cout<<s<<'\n';
    return 0;
}
