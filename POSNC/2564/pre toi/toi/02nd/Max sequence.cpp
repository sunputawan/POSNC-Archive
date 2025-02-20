#include <bits/stdc++.h>

using namespace std;
int qsum[3000]={};
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>qsum[i];
        qsum[i]+=qsum[i-1];
    }
    int ans = 0;
    int l,r;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(qsum[j]-qsum[i-1]>ans){
                ans = qsum[j]-qsum[i-1];
                l = i;
                r = j;
            }
        }
    }
    if(ans){
        for(int i=l;i<=r;i++)
            cout<<qsum[i]- qsum[i-1]<<" ";
        cout<<endl<<ans;
    }
    else{
        cout<<"Empty sequence\n";
    }
}
