#include <bits/stdc++.h>

using namespace std;
long long s(long long i){
    long long l = (long long) 1,r = i;
    while(l<=r){
        long long mid =(l+r)/2;
        if(mid == i/mid)
            return mid;
        if(mid < i/mid)
            l = mid+1;
        else
            r = mid-1;
    }
    return r; // floor()
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long n,q;
    cin>>n>>q;
    while(q--){
        long long l,r;
        cin>>l>>r;
        cout<<s(r)-s((l-1))+s(r/2)-s((l-1)/2)<<'\n';
    }

    return 0;
}
