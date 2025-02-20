#include<iostream>
int cell[5][4]={34,21,22,34,
              45,70,43,65,
              25,62,15,26,
              15,17,32,24,
              30,60,50,80};
using namespace std;
int max_value[5][4];
int max(int a,int b,int c){
    if(a>b){
        if(a>c){
            return a;
        }
        if(c>a)
            return c;
    }
    else{
        if(b>c)
            return b;
        if(c>b)
            return c;
    }
}
int max_path_at(int i,int j){
    if(i==0)
        max_value[i][j]=cell[i][j];
    if(max_value[i][j]==-1){
        if(j==0)
            max_value[i][j]=cell[i][j]+max(max_path_at(i-1,j),max_path_at(i-1,j+1),0);
        if(j==1||j==2)
            max_value[i][j]=cell[i][j]+max(max_path_at(i-1,j-1),max_path_at(i-1,j),max_path_at(i-1,j+1));
        if(j==3)
            max_value[i][j]=cell[i][j]+max(max_path_at(i-1,j-1),max_path_at(i-1,j),0);
    }
    return max_value[i][j];
}
int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++)
            max_value[i][j]=-1;
    }
    cout<<max(max_path_at(4,0),max_path_at(4,1),max(max_path_at(4,2),max_path_at(4,3)))<<endl;
    /*for(int i=0;i<5;i++){
        for(int j=0;j<4;j++)
            cout<<max_value[i][j]<<" ";
        cout<<endl;
    }*/
}
