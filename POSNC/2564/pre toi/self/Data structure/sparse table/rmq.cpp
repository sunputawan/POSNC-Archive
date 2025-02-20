#include <bits/stdc++.h>

using namespace std;
int arr[] = {12,2,4,17,9,5,8,10,20};
const int N = sizeof(arr)/sizeof(arr[0]);
const int K = 4; // ceil(logN)
int st[N][K+1];  //represent the answer of range [i,i+2^j]
int lg[N+1];
int f(int a,int b){
    return min(a,b);
}
int rmq(int l,int r){
    int j = lg[r-l+1];
    return f(st[l][j],st[1+r-(1<<j)][j]);
}
int main(){
    for(int i=2;i<=N;i++){   //precompute to find log in O(1)
        lg[i] = lg[i/2]+1;
    }
    for(int i=0;i<N;i++){
        st[i][0] = arr[i];
    }
    lg[1] = 0;
    for(int j=1;j<=K;j++){
        for(int i=0;i+(1<<j)<=N;i++){
            st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    cout<<rmq(3,7);
    return 0;
}
