#include <bits/stdc++.h>

using namespace std;
long long qsum[100005];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>qsum[i];
        qsum[i]+=qsum[i-1];
    }
    for(int i=1;i<=n;i++)
        cout<<qsum[i]<<" ";
    cout<<endl;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<"target : "<<m+qsum[l-1]<<endl;
        auto it = lower_bound(qsum+l,qsum+r+1,m+qsum[l-1]);
        //cout<<' '<<*it<<endl;
        /*if(*it == m){
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";*/
    }

    return 0;
}
