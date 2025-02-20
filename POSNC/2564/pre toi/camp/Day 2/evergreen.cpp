#include <bits/stdc++.h>

using namespace std;
long long n,k;
long long a[1005];
long long total(long long i,long long j){
    long long len = j-i+1;
    if(len<=0) return 0;
    if(len%2) return (len+1)/2*(len+1)/2;
    else return len/2*(len+2)/2;
}
bool day(long long d){
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=total(a[i]-d,a[i]+d);
        if(i<n-1){
            sum-=total(a[i+1]-d,a[i]+d);
        }
    }
    if(sum>=k)
        return true;
    else
        return false;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long l=0,r=1e9;
    while(l<r){
        long long mid = (l+r)/2;
        if(day(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
