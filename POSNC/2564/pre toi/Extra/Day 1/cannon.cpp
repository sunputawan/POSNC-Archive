#include <bits/stdc++.h>

using namespace std;
int a[1000005];
int main(){
    int n,m,k,l;
    cin>>n>>m>>k>>l;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    while(k--){
        int i=0,ans=0;
        int x;
        for(int j=0;j<m;j++){
            cin>>x;

            if(i==n) continue;
            while(i<n && a[i]<x-l)
                i++;
            while(i<n && a[i]<=x+l){
                i++; ans++;
            }
        }
        cout<<ans<<endl;
    }

}
