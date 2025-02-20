#include <bits/stdc++.h>

using namespace std;
int n;
bool visited[1005];
int a[1005];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt = n;
    int ans = 0;
    while(cnt>0){
        //cout<<cnt<<endl;
        int mx = 0;
        int idx;
        for(int i=1;i<cnt;i++){
            int dif = abs(a[i]-a[i+1]);
            if(mx<dif){
                mx = dif;
                idx = i;
            }
        }
        ans+=mx;
        for(int i=idx;i<=n;i++){
            a[i] = a[i+2];
        }
        cnt-=2;
    }
    cout<<ans<<endl;
}
