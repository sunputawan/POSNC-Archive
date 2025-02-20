#include <bits/stdc++.h>

using namespace std;
int a[1005];
int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    while(m--){
        int l,r; cin>>l>>r;
        r+=l-1;
        for(int i=0;i<=(r-l)/2;i++){
            int x = l+i , y = r-i;
            if(x>n) x-=n;
            if(y>n) y-=n;
            swap(a[x],a[y]);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }

    cout<<'\n';
}