#include <iostream>
#define INTMAX 999999999

using namespace std;
int d[] = {2,4,2,1,5,2};  //Matrix[i] = d[i] * d[i-1];
const int n = sizeof(d)/sizeof(d[0]);
int M[n+1][n+1]={}; //M[i][i] = 0;
int m(int i,int j){
    if(i==j)
        return 0;
    if(M[i][j]==INTMAX){
        for(int k=i;k<=j;k++){
            M[i][j] = min(M[i][j],m(i,k)+m(k+1,j)+d[i-1]*d[k]*d[j]);
        }
    }
    return M[i][j];
}
int main(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            M[i][j] = INTMAX;
    cout<<m(1,n);
}
