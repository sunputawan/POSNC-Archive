#include <bits/stdc++.h>

using namespace std;
vector<int> v[2][2];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x; cin>>x;
            v[i%2][j%2].push_back(x);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            sort(v[i][j].begin(),v[i][j].end());
        }
    }
    int ans = 0;
    for(int i=0;i<n*n/4;i++){
        int mul=1;
        mul = v[0][0][i]*v[0][1][i]*v[1][0][i]*v[1][1][i];
        ans+=mul;
    }
    cout<<ans<<endl;
    return 0;
}
