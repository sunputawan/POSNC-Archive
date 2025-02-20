#include <bits/stdc++.h>

using namespace std;
int a[1000005],mn = __INT_MAX__;
int main(){
    int n,k,p; cin>>n>>k>>p;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mn = min(mn,a[i]);
    }

    int l = mn, r = 1e9;
    while(l<r){
        int mid = (l+r)/2;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                cnt++;
                i += p-1;
            }
        }
        if(cnt<=k) r = mid;
        else l = mid+1;
    }

    cout<<r<<'\n';
    return 0;
}