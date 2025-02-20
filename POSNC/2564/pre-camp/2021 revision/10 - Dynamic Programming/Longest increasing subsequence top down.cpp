#include <iostream>

using namespace std;
string x = "ANALYSIS";
string y = "ALGORITHMS";
int n = x.size(); int m = y.size();
int CS[1000][1000] = {};
bool track[1000] = {};
void initialize(void){
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            CS[i][j] = -1;
    cout<<"string ref : "<<"\""<<x<<"\",\""<<y<<"\""<<endl;
}
// recurrence relation : CS[i][j] represents size of the longest common subsequence
//                                between string X (size i) and string Y (size j).
//
//                      LCS(i,j) = 1+LCS(i-1,j-1)               ; x[i] = y[j]
//                               = max(LCS(i-1,j),LCS(i,j-1))   ; i!=0 && j!=0
//                               = 0                            ; i==0 || j==0
int LCS(int i,int j){
    if(i==0||j==0){
        if(x[i]==y[j])
            track[i] = true;
        return 0;
    }
    if(CS[i][j]==-1){
        if(x[i]==y[j]){
            CS[i][j] = 1+LCS(i-1,j-1);
            //cout<<x[i]<<endl;
            track[i] = true;
        }
        else{
            CS[i][j] = max(LCS(i-1,j),LCS(i,j-1));
        }
    }
    return CS[i][j];
}
void print_str(void){
    for(int i=0;i<n;i++)
        if(track[i])
            cout<<char(x[i]);
}
int main(){
    initialize();
    cout<<"Longest common subsequence : "<<LCS(n,m)<<" ("; print_str(); cout<<')';
}
