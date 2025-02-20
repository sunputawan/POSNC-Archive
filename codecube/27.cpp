#include <bits/stdc++.h>

using namespace std;
int bulb[25],tmp[25];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>bulb[i];
        bulb[i]++;
    }
    int ans = 25;
    for(int bit=0;bit<(1<<n);bit++){
        memset(tmp,0,sizeof(tmp));
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(bit & (1<<i)){
                if(i>0)
                    tmp[i-1]++;
                tmp[i]++;
                tmp[i+1]++;
                cnt++;
            }
        }
        bool alloff = true;
        for(int i=0;i<n;i++){
            if(tmp[i]%2==bulb[i]%2){
                alloff = false;
                break;
            }
        }
        if(alloff){
            ans = min(ans,cnt);
        }
    }
    if(ans==25) cout<<-1<<'\n';
    else cout<<ans<<'\n';
    return 0;
    
}