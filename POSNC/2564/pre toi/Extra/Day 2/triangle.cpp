#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int main(){
    int n;
    cin>>n;
    if(n<3){
        cout<<"no\n";
        return 0;
    }
    for(int i=0;i<n;i++){
        int x; cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    if(v[0]+v[1]<=v[n-1])
        cout<<"yes\n";
    else
        cout<<"no\n";

    return 0;
}
