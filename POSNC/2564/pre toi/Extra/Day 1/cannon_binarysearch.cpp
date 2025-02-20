#include <bits/stdc++.h>

using namespace std;
int n,m,k,l;
vector<int> v;
bool visited[1000001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m>>k>>l;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    while(k--){
        memset(visited,false,sizeof(visited));
        int num,ans=0;
        for(int i=0;i<m;i++){
            cin>>num;
            int lb = lower_bound(v.begin(),v.end(),num-l)-v.begin();
            for(int j=lb;v[j]<=num+l&&j<n;j++){
                if(!visited[j]){
                    visited[j] = true;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}
