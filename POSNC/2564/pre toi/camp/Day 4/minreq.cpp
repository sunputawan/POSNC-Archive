#include <bits/stdc++.h>

using namespace std;
int li[11];
int a[11];
int s[10000005];
int t[11];
int q[11];
int n,m,x,l;
bool solve(int t){
    int mark[n+2];
    bool goon = true;
    for(int i=1;i<=n;i++){
        int check = 0;
        for(int j=1;j<=n;j++){
            if(mark[j]) continue;
            int cnt = 0,ch=1,ll=q[i],rr=q[i+1];
            while(ll<rr){
                int idx = upper_bound(s+1,s+rr,li[j]-a[i]+s[ll-1])-s;
                cnt++;
                if(cnt>t) ch=0;
                ll = idx;
            }
            if(ch){
                mark[j]=1;
                check = 1;
                break;
            }
        }
        if(!check) return false;
    }
    return true;
}
int main(){
    cin>>n>>m>>x>>l;
    for(int i=1;i<=n;i++)
        cin>>li[i];
    sort(l+1,l+n+1);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++){
        cin>>s[i];
        s[i]+=s[i-1];
    }
    for(int i=1;i<=x;i++)
        cin>>t[i];
    int cnt = 1;
    while(cnt<=x){
        for(int i=1;i<=n;i++)
            cin>>q[i];
        q[n+1] = m;
        bool can = false;
        do{
            if(solve(t[cnt])){
                can = true;
                break;
            }
        }while(next_permutation(a+1,a+n+1));
        if(can)
            cout<<"P\n";
        else
            cout<<"F\n";
    }

}
