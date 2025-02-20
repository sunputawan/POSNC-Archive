#include <bits/stdc++.h>

using namespace std;
string x;
short cnt[50005][26],mx[50005];
int main(){
    cin>>x;
    int n = x.size();
    int ans = 100005;
    for(int l=1;l<=n/2;l++){
        if(n%l) continue;

        memset(cnt,0,sizeof cnt);
        memset(mx,0,sizeof mx);
        for(int i=0;i<n;i++){
            cnt[i%l][x[i]-'a']++;
            mx[i%l] = max(mx[i%l],cnt[i%l][x[i]-'a']);
        }
        int curans = 0;
        for(int i=0;i<l;i++){
            curans+=(n/l-mx[i]);
        }
        ans = min(ans,curans);
    }
    cout<<ans<<endl;
    return 0;
}
