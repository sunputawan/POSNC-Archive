#include <iostream>
#define inf 999999

using namespace std;
int n,money;
int v[50],m[50][50];
int min(int a,int b){
    if(a<b) return a;
    else return b;
}
int M(int i,int j){
    if(j==0)
        m[i][j]=0;
    if(i==0)
        m[i][j]=inf;
    if(m[i][j]==-1){
        if(j>=v[i-1])
            m[i][j]=min(1+M(i,j-v[i-1]),M(i-1,j));
        else
            m[i][j]=M(i-1,j);
    }
    return m[i][j];
}
int main(){
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter money :";
    cin>>money;
    for(int i=0;i<n;i++){
        cout<<"Enter coin"<<i+1<<" value :";
        cin>>v[i];
    }
    for(int i=0;i<=n;i++){
        for(int k=0;k<=money;k++)
            m[i][k]=-1;
    }
    cout<<M(n,money);
    /*for(int i=0;i<=n;i++){
        for(int k=0;k<=money;k++){
            cout<<m[i][k]<<" ";
        }
        cout<<endl;
    }*/
}
