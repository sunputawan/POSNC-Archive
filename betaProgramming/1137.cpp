#include <bits/stdc++.h>

using namespace std;
long long sum = 0;
int main(){
    int n; cin>>n;
    long long mn; cin>>mn;
    for(int i=1;i<n;i++){
        long long x; cin>>x;
        sum += x;
    }
    sum += mn*(n-2);
    cout<<sum<<'\n';

    return 0;
}