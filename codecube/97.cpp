#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    int n; cin>>n;
    int sq = sqrt(n);
    //v.push_back(1);
    for(int i=1;i<=sq;i++){
        if(n%i) continue;
        v.push_back(i);
        if(n/i!=i) v.push_back(n/i);
    }
    sort(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<' ';
    }

    return 0;
}