#include <iostream>

using namespace std;
long long path[51][51]={};
int main(){
    int m,n,o;
    cin>>m>>n>>o;
    for(int i=0;i<o;i++){
        int a,b;
        cin>>a>>b;
        path[a][b]=-1;
    }
    for(int i=1;i<=m;i++){
        if(path[i][1]==-1)
            break;
        path[i][1]=1;
    }
    for(int i=1;i<=n;i++){
        if(path[1][i]==-1)
            break;
        path[1][i]=1;
    }
    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            if(path[i][j]==-1)
                continue;
            if(path[i-1][j]==-1)
                path[i][j] = path[i][j-1];
            if(path[i][j-1]==-1)
                path[i][j] = path[i-1][j];
            if(path[i-1][j]!=-1&&path[i][j-1]!=-1)
                path[i][j] = path[i-1][j]+path[i][j-1];
        }
    }
    cout<<path[m][n];
}
