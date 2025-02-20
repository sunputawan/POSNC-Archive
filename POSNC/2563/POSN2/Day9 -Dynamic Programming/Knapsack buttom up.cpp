#include <iostream>
int W,n;
int v[50],w[50];
int C[50][50];
int Max(int a,int b){
    if(a>b) return a;
    else    return b;
}
int opt(int n,int W){
    for(int i=0;i<n+1;i++)
        C[i][0]=0;
    for(int i=0;i<n+1;i++)
        C[0][i]=0;
    for(int i=1;i<n+1;i++)
        for(int j=1;j<W+1;j++){
            if(j<w[i])
                C[i][j]=C[i-1][j];
            else
                C[i][j]=Max(C[i-1][j-w[i]]+v[i],C[i-1][j]);

        }
    return C[n][W];
}
using namespace std;
int main(){
    cout<<"Enter n :";
    cin>>n;
    cout<<"Enter W :";
    cin>>W;
    for(int i=1;i<=n;i++){
        cout<<"\tEnter value"<<i<<" :";
        cin>>v[i];
        cout<<"\tEnter weight"<<i<<" :";
        cin >>w[i];
        cout<<"\n";
    }
    cout<<opt(n,W);
}

