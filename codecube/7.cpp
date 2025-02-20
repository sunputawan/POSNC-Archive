#include <bits/stdc++.h>

using namespace std;
string a,b;
int k[1000005];
int main(){
    cin>>a>>b;
    int n = a.size();
    for(int i=0;i<n;i++){
        if(a[i]>='a') a[i]-=32;
        if(b[i]>='a') b[i]-=32;
        a[i]-=65;
        b[i]-=65;
        int diff = a[i]-b[i];
        if((diff<0||diff>9)&&(diff+26<0||diff+26>9)){
            cout<<"R.I.P.\n";
            return 0;
        }
        k[i] = a[i]-b[i];
        if(k[i]<0) k[i]+=26;
    }
    for(int i=0;i<n;i++){
        cout<<k[i];
    }
    cout<<'\n';
    return 0;
}