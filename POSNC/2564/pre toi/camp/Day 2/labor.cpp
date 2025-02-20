#include <bits/stdc++.h>

using namespace std;
long long m,n,mid;
long long t[1000005];
long long total(void){
    long long sum = 0;
    for(int i=0;i<m;i++){
        sum+=mid/t[i];
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    long long l = 0,r=1e18+5;
    while(l<r){
        mid = (l+r)/2;
        long long sum = total();
        if(sum<n)
            l=mid+1;
        else
            r=mid;
    }
    cout<<l;
    return 0;
}
