#include <bits/stdc++.h>

using namespace std;
long long a[2000005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long l=0,r=2e10;
    while(l<r){
        long long mid = (l+r)/2;
        vector<long long> scope;
        for(int i=0;i<n;i++){
            if(mid<a[i])
                scope.push_back(a[i]);
        }
        bool able = true;
        for(int i=0;i<scope.size();i+=2){
            if(scope[i]!=scope[i+1]){
                able=false; break;
            }
        }
        if(able){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout<<l;
    return 0;
}
