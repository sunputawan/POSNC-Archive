#include <iostream>

using namespace std;
int a[5][4] = {34,21,22,34,
               45,70,43,65,
               25,62,15,26,
               15,19,32,24,
               30,60,50,80};
int path[5][4]={};
int puzzle(){
    for(int i=0;i<4;i++)
        path[0][i] = a[0][i];
    for(int i=1;i<5;i++){
        path[i][0] = a[i][0]+max(path[i-1][0],path[i-1][1]);
        path[i][3] = a[i][3]+max(path[i-1][2],path[i-1][3]);
        path[i][1] = a[i][1]+max(path[i-1][1],max(path[i-1][0],path[i-1][2]));
        path[i][2] = a[i][2]+max(path[i-1][2],max(path[i-1][1],path[i-1][3]));
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++)
            cout<<path[i][j]<<' ';
        cout<<endl;
    }
    return max(path[4][0],max(path[4][1],max(path[4][2],path[4][3])));
}
int main(){
    cout<<puzzle();
}
