#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    int n,k,x; cin>>n>>k;
    while(n--){
        cin>>x; v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    cout<<v[k-1]<<'\n';

    return 0;
}