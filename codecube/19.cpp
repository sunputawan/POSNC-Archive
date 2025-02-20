#include <bits/stdc++.h>

using namespace std;
vector<int> v(100005);
int n,k;
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }

    for(int cnt=0;cnt<k;cnt++){
        for(int i=1;i<=n-cnt;i++){
            if(i==n-cnt||(v[i]>v[i+1])){
                v.erase(v.begin()+i);
                break;
            }
        }
    }
    for(int i=1;i<=n-k;i++){
        cout<<v[i]<<' ';
    }

    cout<<'\n';
    return 0;
}