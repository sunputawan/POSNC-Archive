#include <bits/stdc++.h>

using namespace std;
int m,n;
vector<pair<long long,long long>> v;
long long ans[4];
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int x,s,t; cin>>x>>s>>t;
        v.push_back({s,x});
        v.push_back({t+1,-x});
    }
    sort(v.begin(),v.end());
    int last = -1;
    int cnt  = 0;
    long long mx = 1;
    for(auto x:v){
        long long now = (ans[0]+1)*(ans[1]+1)*(ans[2]+1)*(ans[3]+1);
        if(now>mx){
            mx = now; cnt = x.first-last;
        }
        else if(now==mx){
            cnt += x.first-last;
        }
        last = x.first;
        switch(x.second){
            case 2: ans[0]++; break;
            case 3: ans[1]++; break;
            case 4: ans[0]+=2; break;
            case 5: ans[2]++; break;
            case 6: ans[0]++,ans[1]++; break;
            case 7: ans[3]++; break;
            case 8: ans[0]+=3; break;
            case 9: ans[1]+=2; break;
            case 10: ans[0]++,ans[2]++; break;

            case -2: ans[0]--; break;
            case -3: ans[1]--; break;
            case -4: ans[0]-=2; break;
            case -5: ans[2]--; break;
            case -6: ans[0]--,ans[1]--; break;
            case -7: ans[3]--; break;
            case -8: ans[0]-=3; break;
            case -9: ans[1]-=2; break;
            case -10: ans[0]--,ans[2]--; break;
        }
    }
    cout<<mx<<" "<<cnt<<endl;
    return 0;
}
