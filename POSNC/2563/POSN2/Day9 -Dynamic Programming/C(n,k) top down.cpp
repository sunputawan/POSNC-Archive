#include <iostream>
int C[1000][1000];
using namespace std;
int c(int n,int k){
    if(n==k || k==0)
        return 1;
    if(k<0||k>n)
        return 0;
    if(C[n][k]==-1)
        C[n][k]=c(n-1,k)+c(n-1,k-1);
    return C[n][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            C[i][j]=-1;
        }
    }
    cout<<"C("<<n<<","<<k<<") = "<<c(n,k)<<endl;
}
