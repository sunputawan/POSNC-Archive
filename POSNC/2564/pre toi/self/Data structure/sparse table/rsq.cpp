#include <bits/stdc++.h>

using namespace std;
int arr[] = {12,2,4,17,9,5,8,10,20};
const int N = sizeof(arr)/sizeof(int);
const int K = 4;
long long st[N][K+1];
int f(int a,int b){
    return a+b;
}
long long sum(int l,int r){
    long long ans = 0;
    for(int j=K;j>=0;j--){
        if((1<<j)<=r-l+1){
            ans+= st[l][j];
            l += 1<<j;
        }
    }
    return ans;
}
int main(){
    for(int i=0;i<N;i++)
        st[i][0] = arr[i];

    for(int j=1;j<=K;j++)
        for(int i=0;i+(1<<j)<=N;i++)
            st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1]);

    cout<<sum(3,7);
    return 0;
}
