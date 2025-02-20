#include <bits/stdc++.h>

using namespace std;
vector<long long> a,b;
long long sum;
int n,k; 
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n-1;i++){
        b.push_back(a[i+1]-a[i]);
        cout<<b[i]<<' ';
    }
    cout<<'\n';
    sort(b.begin(),b.end());
    cout<<'\n';
    for(int i=0;i<k;i++){
        sum += b[i];
    }

    cout<<sum<<'\n';
}