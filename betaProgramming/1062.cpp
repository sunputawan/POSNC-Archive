#include <bits/stdc++.h>

using namespace std;
int n,m;
string a,b,x;
int main(){
    cin>>m>>n;
    cin>>a>>b>>x;
    for(int i=0;i<m;i++){
        if(a[i]>b[i])
            swap(a[i],b[i]);
    }
    for(int i=0;i<n;i++){
        a = 'A' + a;
        b = 'Z' + b;
    }
    for(int i=0;i<n;i++){
        a.push_back('A');
        b.push_back('Z');
    }
    m = a.size();
    for(int i=0;i<m-n+1;i++){
        for(int j=0;j<n;j++){
            if(x[j]<a[i+j])
                x[j] = a[i+j];
            else if(x[j]>b[i+j])
                x[j] = b[i+j];
        }
    }
    cout<<x<<'\n';
    return 0;
}