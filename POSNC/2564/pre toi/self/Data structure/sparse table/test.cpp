#include <bits/stdc++.h>

using namespace std;
int st[100005][17];  //represent the answer of range [i,i+2^j]
int lg[100005];
int f(int a,int b){
    return min(a,b);
}
int rmq(int l,int r){
    int j = lg[r-l+1];
    return f(st[l][j],st[1+r-(1<<j)][j]);
}
int N,K,q;
int main(){
	cin>>N;
    for(int i=2;i<=N;i++){   //precompute to find log in O(1)
        lg[i] = lg[i/2]+1;
    }
    K = lg[N];
    for(int i=0;i<N;i++){
        cin>>st[i][0];
    }
    lg[1] = 0;
    for(int j=1;j<=K;j++){
        for(int i=0;i+(1<<j)<=N;i++){
            st[i][j] = f(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
   	cin>>q;
   	while(q--){
   		int a,b; cin>>a>>b;
   		cout<<rmq(a,b)<<'\n';
   	}
    return 0;
}
