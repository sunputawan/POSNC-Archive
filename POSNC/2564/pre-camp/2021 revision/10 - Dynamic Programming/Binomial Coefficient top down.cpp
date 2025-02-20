#include <iostream>

using namespace std;
int C[10000][10000];
int combination(int n,int k){
    if(n==0||n==k||k==0)
        return 1;
    if(C[n][k]==-1)
        C[n][k] = combination(n-1,k) + combination(n-1,k-1);
    return C[n][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            C[i][j] = -1;
    combination(n,k);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++)
            cout<<C[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl<<combination(n,k)<<endl;
}
