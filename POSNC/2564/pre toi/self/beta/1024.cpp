#include <bits/stdc++.h>

using namespace std;
int qsum[1005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        cin>>qsum[i];
        qsum[i]+=qsum[i-1];
    }
    int a,b,c;
    int ans2,ans3;
    int d = 2000000000;
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            a = qsum[i];
            b = qsum[j]-qsum[i];
            c = qsum[n]-qsum[j];
            int diff = max(a,max(b,c))-min(a,min(b,c));
            if(diff<d){
                d=diff;
                ans2 = i+1;
                ans3 = j+1;
            }
        }
    }
    cout<<ans2<<" "<<ans3;

}
