#include <iostream>
int m1,n1,m2,n2,t;
int a1[500][500]={};
long long p1[500][500];
int a2[500][500]={};
long long p2[500][500];
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
void quick_sum1(int x,int y){
    p1[0][0]=a1[0][0];
    for(int i=1;i<x;i++)
        p1[i][0]=a1[i][0]+p1[i-1][0];
    for(int i=1;i<y;i++)
        p1[0][i]=a1[0][i]+p1[0][i-1];
    for(int i=1;i<x;i++){
        for(int j=1;j<y;j++){
            p1[i][j]=a1[i][j]+p1[i-1][j]+p1[i][j-1]-p1[i-1][j-1];
        }
    }
}
void quick_sum2(int x,int y){
    p2[0][0]=a2[0][0];
    for(int i=1;i<x;i++)
        p2[i][0]=a2[i][0]+p2[i-1][0];
    for(int i=1;i<y;i++)
        p2[0][i]=a2[0][i]+p2[0][i-1];
    for(int i=1;i<x;i++){
        for(int j=1;j<y;j++){
            p2[i][j]=a2[i][j]+p2[i-1][j]+p2[i][j-1]-p2[i-1][j-1];
        }
    }
}
long long find_sum1(int i,int j,int z){
    if(i<z&&j>=z){
        return p1[i][j]-p1[i][j-z];
    }
    if(j<z&&i>=z){
        return p1[i][j]-p1[i-z][j];
    }
    if(j<z&&i<z){
        return p1[i][j];
    }
    if(j>=z&&i>=z){
        return p1[i][j]-p1[i-z][j]-p1[i][j-z]+p1[i-z][j-z];
    }
}
long long find_sum2(int i,int j,int z){
    if(i<z&&j>=z){
        return p2[i][j]-p2[i][j-z];
    }
    if(j<z&&i>=z){
        return p2[i][j]-p2[i-z][j];
    }
    if(j<z&&i<z){
        return p2[i][j];
    }
    if(j>=z&&i>=z){
        return p2[i][j]-p2[i-z][j]-p2[i][j-z]+p2[i-z][j-z];
    }
}
int find_garden1(int x,int y){
    quick_sum1(x,y);
    int max_z=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a1[i][j]==0){
                max_z=1;
                break;
            }
        }
    }
    if(max_z==1){
        for(int z=2;z<=min(x,y);z++){
            for(int i=z-1;i<x;i++){
                for(int j=z-1;j<y;j++){
                    if(find_sum1(i,j,z)==find_sum1(i-1,j-1,z-2))
                        max_z=z;
                }
            }
        }
    }

    return max_z;
}
int find_garden2(int x,int y){
    quick_sum2(x,y);
    int max_z=0;
     for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a2[i][j]==0){
                max_z=1;
                break;
            }
        }
    }
    if(max_z==1){
        for(int z=2;z<=min(x,y);z++){
            for(int i=z-1;i<x;i++){
                for(int j=z-1;j<y;j++){
                    if(find_sum2(i,j,z)==find_sum2(i-1,j-1,z-2))
                        max_z=z;
                }
            }
        }
    }
        return max_z;
}
using namespace std;
int main(){
    int x,y;
    cin>>m1>>n1;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        a1[x][y]=1;
    }
    cin>>m2>>n2;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        a2[x][y]=1;
    }
    cout<<find_garden1(m1,n2)<<endl;
    cout<<find_garden2(m2,n2);
}
