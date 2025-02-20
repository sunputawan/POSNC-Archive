#include <iostream>
int n,W;
int w[50],v[50];
int C[50][50];
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int opt(int i,int j){
    if(i==0||j==0){
        C[i][j]=0;
        return C[i][j];
    }
    if(C[i][j]==-1){
        if(j>=w[i])
            C[i][j]=max(opt(i-1,j-w[i])+v[i],opt(i-1,j));
        else
            C[i][j]=opt(i-1,j);
    }
    return C[i][j];
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++)
            C[i][j]=-1;
    }
    opt(n,W);
    cout<<opt(n,W);
}
