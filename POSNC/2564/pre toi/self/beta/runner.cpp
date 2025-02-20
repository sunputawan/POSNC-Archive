#include <bits/stdc++.h>

using namespace std;
struct A{
    int num,lan,velo;
}r[100005];
int lane[10005];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,l,s;
        cin>>a>>l>>s;
        lane[l]++;
        if(s>r[lane[l]].velo||(r[lane[l]].velo==s&&l<r[lane[l]].lan)){
            r[lane[l]] = {a,l,s};
        }
    }
    int i=1;
    while(r[i].num!=0){
        cout<<r[i++].num<<'\n';
    }
    return 0;
}
