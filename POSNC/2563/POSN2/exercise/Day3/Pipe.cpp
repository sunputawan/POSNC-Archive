#include <iostream>
#include <vector>
using namespace std;
int m,n;
int p[300][300];
vector<int> v;
int count;
int path(int i,int j){
    if(i<0||i>=m||j<0||j>=n){
        return count;
    }
    count++;
    p[i][j]=0;
    if(p[i][j]==11){
        path(i,j-1);
    }
    if(p[i][j]==12){
        path(i,j+1);
    }

}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>p[i][j];
        }
    }
    for(int i=0;i<m;i++){
        count=0;
        path(i,0);
    }
}
