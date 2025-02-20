#include <bits/stdc++.h>

using namespace std;
int cs[1000005],n,m;
long long cnt;
int main(){
    cin>>n>>m;
    while(n--){
        int a; cin>>a;
        cs[a]++;
    }
    if(m%2==0){
        cnt += ((long long)cs[m/2])*(cs[m/2]-1)/2;
    }

    for(int i=0;i<=(m-1)/2;i++){
        cnt += ((long long)cs[i])*cs[m-i];
    }

    cout<<cnt<<'\n';
}