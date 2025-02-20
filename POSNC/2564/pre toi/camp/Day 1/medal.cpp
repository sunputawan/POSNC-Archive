#include <bits/stdc++.h>

using namespace std;
int a[500005],b[500005],c[500005];
bool ascending(int a,int b){
    return a<=b;
}
bool descending(int a,int b){
    return a>=b;
}
int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    sort(a,a+n,ascending);
    sort(b,b+n,descending);

    for(int i=0;i<n;i++)
        c[i] = a[i]+b[i];

    sort(c,c+n);

    cout<<c[n-1]-c[0];
    return 0;
}
