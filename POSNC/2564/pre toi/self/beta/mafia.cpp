#include <bits/stdc++.h>

using namespace std;
int dpx[5005];
int dpy[5005];
int n,m,k;
int main(){
    cin>>n>>m>>k;
    n++,m++;
    while(k--){
        int x,y,r;
        cin>>x>>y>>r;
        x++,y++;
        dpx[max(1,y-r)]++, dpx[min(m+1,y+r+1)]--;
        dpy[max(1,x-r)]++, dpy[min(m+1,x+r+1)]--;
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        dpy[i] += dpy[i-1];
        mx = max(mx,dpy[i]);
    }
    for(int i=1;i<=m;i++){
        dpx[i] += dpx[i-1];
        mx = max(mx,dpx[i]);
    }
    cout<<mx<<'\n';
    return 0;
}
