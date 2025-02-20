#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> a;
vector<vector<int>> ans;
int n,m,t[20];
void solve(void){
    cin>>n>>m;
    a.clear();
    ans.clear();
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int sz; cin>>sz;
        while(sz--){
            char opr,var; cin>>opr>>var;
            if(opr=='-') tmp.push_back(-(var-'a'+1));
            else tmp.push_back(var-'a'+1);
        }
        a.push_back(tmp);
    }

    for(int i=0;i<m;i++){
        vector<int> tmp;
        int sz; cin>>sz;
        while(sz--){
            char opr,var; cin>>opr>>var;
            if(opr=='-') tmp.push_back(-(var-'a'+1));
            else tmp.push_back(var-'a'+1);
        }
        ans.push_back(tmp);
    }

    for(int bit=0;bit<(1<<16);bit++){

        for(int i=0;i<16;i++){
            t[i+1] = (((1<<i) & bit)!=0);
        }
        bool truth1 = true;
        for(auto clause:a){
            bool tt = false;
            for(auto p:clause){
                if(p<0) tt |= !t[-p];
                else tt |= t[p];
            }
            if(tt==false){
                truth1 = false;
                break;
            }
        }
        bool truth2 = true;
        for(auto clause:ans){
            bool tt = false;
            for(auto p:clause){
                if(p<0) tt |=!t[-p];
                else tt |= t[p];
            }
            if(tt==false){
                truth2 = false;
                break;
            }
        }
        if((!truth1||truth2)==false){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    return;
}
int main(){
    int q; cin>>q;
    while(q--){
        solve();
    }
}
/*
2
3 1
2 -a +b
2 -b +c
1 -c
1 -a
1 1
1 +b
1 -a
*/