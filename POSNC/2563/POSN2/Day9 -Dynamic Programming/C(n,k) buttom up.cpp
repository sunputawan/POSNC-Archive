#include <iostream>
int C[1000][1000];
using namespace std;
int c(int n,int k){
    for(int i=0;i<=n;i++){
        C[i][0]=1;
        C[i][i]=1;
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    return C[n][k];
}
int main(){
    int n,k;
    cin>>n>>k;
    cout<<"C("<<n<<","<<k<<") = "<<c(n,k)<<endl;
}
