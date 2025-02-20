#include <bits/stdc++.h>

using namespace std;
int n,k,qs[1005],mx;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>qs[i];
        mx = max(mx,qs[i]);
        qs[i] += qs[i-1];
    }

    int l = mx, r = 2000000, ans = -1,mid;
    while(l<=r){
        mid = (l+r)/2;
        int num = 0, idx = 1;
        while(idx<=n){
            idx = upper_bound(qs+1,qs+n+1,qs[idx-1]+mid)-(qs);
            num++;
        }
        if(num<=k){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}

/*
5 3
3 8 1 9 1
*/