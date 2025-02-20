#include <iostream>
using namespace std;
int m,n,o;
int dog[50][50]={};
long long path [50][50];
bool check_dog(int a,int b){
    if(dog[a][b]==1)
        return 1;
    else
        return 0;
}
void print_array(void){
    cout<<endl<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dog[i][j]<<" ";
        }
        cout<<endl;
    }
}
long long find_path(int i,int j){
    if(check_dog(i,j)){
        path[i][j]=0;
    }
    if(path[i][j]==-1){
        if(i<n-1&&j>0)
            path[i][j]=find_path(i+1,j)+find_path(i,j-1);
        if(i==n-1&&j>0)
            path[i][j]=find_path(i,j-1);
        if(i<n-1&&j==0)
            path[i][j]=find_path(i+1,j);
        if(i==n-1&&j==0)
            path[i][j]=1;
    }
    return path[i][j];
}
int main(){
    int a,b;
    cin>>m>>n; //m=n-s, n=w-e;
    cin>>o;
    for(int i=0;i<o;i++){
        cin>>a>>b;
        dog[n-b][a-1]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            path[i][j]=-1;
        }
    }
    cout<<find_path(0,m-1);
}
