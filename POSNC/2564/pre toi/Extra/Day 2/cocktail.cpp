#include <bits/stdc++.h>

using namespace std;
long long cs[200005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cs[x]++;
    }
    int k; cin>>k;
    long long ans = 0;
    for(int i=0;i<=k/2;i++){
        if(i==k-i)
            ans+=(cs[i]*(cs[i]-1))/2;
        else
            ans+=cs[i]*cs[k-i];
    }
    cout<<ans<<endl;
    return 0;
}
