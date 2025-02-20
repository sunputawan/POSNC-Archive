#include <iostream>

using namespace std;
int C[10000][10000];
int combination(int n,int k){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++)
        C[i][0] = 1;
    cout<<combination(n,k)<<endl<<endl;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}
