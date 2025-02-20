#include <bits/stdc++.h>

using namespace std;
int arr[] = {12,4,18,6,24,8,27,9,30};
const int N = sizeof(arr)/sizeof(int);
const int K = 4;
int st[N][K+1];
int lg[N+1];
int gcd(int a,int b){
    if(b==0)
        return a;

    return gcd(b,a%b);

}
int f(int a,int b){
    return gcd(a,b);
}
int ans(int l,int r){
    int j = lg[r-l+1];
    return f(st[l][j],st[1+r-(1<<j)][j]);
}
int main(){
    lg[1]=0;
    for(int i=2;i<=N;i++)
        lg[i] = lg[i/2]+1;

    for(int i=0;i<N;i++)
        st[i][0] = arr[i];

    for(int j=1;j<=K;j++){
        for(int i=0;i+(1<<j)<=N;i++)
            st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }

    cout<<ans(6,7);

    return 0;
}
