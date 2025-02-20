#include <iostream>

using namespace std;
string x = "ALGORITHMS";
string y = "ANALYSIS";
int LD[100][100];
int min(int a,int b,int c){
    if(a<=b&&a<=c)
        return a;
    else if(b<=a&&b<=c)
        return b;
    else
        return c;
}
int ld(int i,int j){
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(LD[i][j]==-1){
        if(x[i-1]==y[j-1])
            LD[i][j] = ld(i-1,j-1);
        LD[i][j] = 1+min(ld(i-1,j)+1,ld(i-1,j-1),ld(i,j-1));
    }
    return LD[i][j];

}
int main(){
    const int m = x.size();
    const int n = y.size();
    for(int i=0;i<=m;i++)
        for(int j=0;j<=n;j++)
            LD[i][j] = -1;
    cout<<ld(m,n);
}
