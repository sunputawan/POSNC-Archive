#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        auto it = upper_bound(v.begin(),v.end(),x);
        if(it == v.end())
            v.push_back(x);
        else
            *it = x;
    }

    cout<<n-v.size();
}
