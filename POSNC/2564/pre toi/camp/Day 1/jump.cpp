#include <bits/stdc++.h>

using namespace std;
int a[30005];
int n,k;
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int best = 0;
    for(int i=0;i<n;i++){
        int cnt = upper_bound(a,a+n,a[i]+k)-a-i-1;
        best =  max(best,cnt);
    }
    cout<<best;
    return 0;
}
