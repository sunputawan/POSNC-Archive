#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    int ans = 0;
    ans+=(n/15)*3000;
    n%=15;
    if(n>=9){
        ans+=3000;
    }
    else if(n>=4){
        n-=5;
        ans+=1500;
    }
    if(n>0){
        if(n==1)
            ans+=500;
        else if(n==2)
            ans+=800;
        else if(n==3)
            ans+=1300;
    }
    cout<<ans;
}
