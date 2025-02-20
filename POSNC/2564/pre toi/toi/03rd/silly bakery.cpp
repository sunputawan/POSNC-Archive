#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    int a=0,b=0,c=0,d=0,e=0;
    while(n--){
        int aa,bb,cc,dd,ee;
        cin>>aa>>bb>>cc>>dd>>ee;
        a+=aa,b+=bb,c+=cc,d+=dd,e+=ee;
    }
    int ans = 0;
    ans+=a;
    ans+=b;
    while(b--){
        if(d>0)
            d--;
        else
            e-=2;
    }
    ans+=c/2;
    if(c%2==1){
        ans++;
        if(d>1)
            d-=2;
        else if(d==1){
            d--; e-=2;
        }
        else
            e-=4;
    }

    if(d>0){
        ans+=d/4;
        if(d%4){ans++;
            int remain = 4-d%4;
            e-=22*remain;
        }
    }
    if(e>0){
        ans+=e/8;
        if(e%8) ans++;
    }

    cout<<ans;
}
