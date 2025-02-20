#include <iostream>
#include <string>
#include <string.h>
int a[50][50];
using namespace std;
string x,y;
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int LCS(int i,int j){
    if(i==0||j==0)
        a[i][j]=0;
    if(a[i][j]==-1){
        if(x[i-1]==y[j-1])
            a[i][j]=1+LCS(i-1,j-1);
        else
            a[i][j]=max(LCS(i-1,j),LCS(i,j-1));
    }
    return a[i][j];
}
int main(){
    cout<<"Enter X :";
    cin>>x;
    cout<<"Enter Y :";
    cin>>y;
    for(int i=0;i<=max(x.length(),y.length());i++){
        for(int j=0;j<=max(x.length(),y.length());j++){
            a[i][j]=-1;
        }
    }
    std::cout<<"Longest Common Subsequence of X and Y : "<<LCS(x.length(),y.length());

}
