#include <iostream>
using namespace std;
int a[60000][100]={};
int main(){
    int n,k=0; cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z; cin>>x>>y>>z;
        k = max(k,x);
        for(int j=y;j<y+z;j++)
            a[x][j] = 1;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=70;j++){
            if(a[i][j]) cout<<'x';
            else cout<<'o';
        }
        cout<<endl;
    }
}
