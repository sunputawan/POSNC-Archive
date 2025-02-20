#include <bits/stdc++.h>

using namespace std;
int n,w;
vector<int> v;
vector<int> a;
int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(abs(x-w));
    }
    for(int i=0;i<n;i++){
        auto it = upper_bound(a.begin(),a.end(),v[i]);
        if(it==a.end()){
            a.push_back(v[i]);
        }
        else{
            *it = v[i];
        }
    }
    cout<<n-a.size()<<endl;
    return 0;
}
