#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    if(n<3){
        cout<<n;
        return 0;
    }
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    int i=0;
    int ans=0;
    for(int last=3;last<n;last++){
        while(v[i]+v[i+1]<=v[last]) i++;
        ans = max(ans,last-i+1);
    }
    cout<<ans;
    return 0;
}
