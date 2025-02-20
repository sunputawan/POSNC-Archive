/*
TASK: location.cpp
LANG: C++
COMPILER: WCB
AUTHOR: Putawan Sratongtuan
CENTER: SSWIT
*/
#include <iostream>
int m,n,k;
int a[2000][2000]={};
int p[2000][2000]={};
int min(int a,int b){
    if(a>b) return b;
    else return a;
}
void quick_sum(void){
    p[0][0]=a[0][0];
    for(int i=1;i<m;i++)
        p[i][0]=a[i][0]+p[i-1][0];
    for(int i=1;i<n;i++)
        p[0][i]=a[0][i]+p[0][i-1];
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            p[i][j]=a[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }
}
int find_sum(int i,int j){
    if(i<k&&j>=k)
        return (p[i][j]-p[i][j-k]);
    if(j<k&&i>=k)
        return (p[i][j]-p[i-k][j]);
    if(j<k&&i<k)
        return p[i][j];
    return (p[i][j]-p[i-k][j]-p[i][j-k]+p[i-k][j-k]);
}
int find_location(void){
    quick_sum();
    int max=0;
    for(int i=k-1;i<m;i++){
        for(int j=k-1;j<n;j++){
            if(find_sum(i,j)>max)
                max=find_sum(i,j);
        }
    }
    return max;
}
using namespace std;
int main(){
    int x;
    cin>>m>>n;
    cin>>k;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>x;
            a[i][j]=x;
        }
    }
    cout<<find_location();
}
