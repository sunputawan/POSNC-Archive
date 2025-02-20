#include <bits/stdc++.h>
using namespace std;
int mp[10005];
int main(){
    int n,k,a;
    cin>>n>>k>>a;
    int page = 1;
    for(int i=1;i<=n;i++){
        int x; cin>>x;
        while(x--){
            mp[page]=i;
            page++;
        }
    }
    int ans = 0;
    int idx;
    for(int i=1;i<page;i++){
        int last = 0,cnt = 0,cur = 0;
        for(int j=i;cnt<k;j+=a,cnt++){
            if(mp[j]&&mp[j]!=last){
                cur++;
                last = mp[j];
            }
        }
        if(ans<cur){
            ans = cur;
            idx = i;
        }
    }
    cout<<idx<<' '<<ans<<'\n';
    return 0;
}
