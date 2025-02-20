#include <bits/stdc++.h>

using namespace std;
int a[2005],b[2005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }
    cout<<ans;
    return 0;
}
