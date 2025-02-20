#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){ 
    int n; cin>>n;

    for(int i=0;i<n;i++){
        int x; cin>>x;
        auto it = lower_bound(v.begin(),v.end(),x);
        if(it==v.end())
            v.push_back(x);
        else
            *it = x;
    }

    cout<<v.size()<<'\n';;
}