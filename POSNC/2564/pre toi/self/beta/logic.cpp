#include <bits/stdc++.h>

using namespace std;
int t[17],n[2],r[2];
void solve(void){
    cin>>n[0]>>n[1];
    vector<vector<int>> v[2];
    for(int q=0;q<2;q++){
        for(int i=1;i<n[q];i++){
            int s; cin>>s;
            vector<int> tmp;
            for(int j=0;j<s;j++){
                char opr,var; cin>>opr>>var;
                tmp.push_back(opr=='+'?(var-'a'+1):-(var-'a'+1));
            }
            v[q].push_back(tmp);
        }
    }
    for(int bit=0;bit<(1<<16);bit++){
        for(int i=0;i<16;i++)
            t[i+1] = (1<<i)&bit;
    }

    return;
}
int main(){
    int k; cin>>k;
    while(k--){
        solve();
    }
    return 0;
}
