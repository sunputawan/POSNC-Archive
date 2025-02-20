#include <iostream>

using namespace std;
string x = "AXYT";
string y = "AYZX";
int n = x.size(); int m = y.size();
int CS[1000][1000] = {};
bool track[1000] = {};
void initialize(void){
    for(int i=0;i<=n;i++)
        CS[i][0] = 0;
    for(int j=0;j<=m;j++)
        CS[0][j] = 0;
    cout<<"string ref : "<<"\""<<x<<"\",\""<<y<<"\""<<endl;
}
// recurrence relation : CS[i][j] represents size of the longest common subsequence
//                                between string X (size i) and string Y (size j).
//
//                      LCS(i,j) = 1+LCS(i-1,j-1)               ; x[i] = y[j]
//                               = max(LCS(i-1,j),LCS(i,j-1))   ; i!=0 && j!=0
//                               = 0                            ; i==0 || j==0
int LCS(void){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(x[i]==y[j]) {
                CS[i+1][j+1] = CS[i][j]+1;
                cout<<i<<' '<<j<<endl;
            }
            else CS[i+1][j+1] = max(CS[i][j+1],CS[i+1][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            cout<<CS[i][j]<<" ";
        cout<<endl;
    }
    return CS[n][m];
}
void print_str(void){
    int current_size = 0;
    int i=0,j=0;
    while(current_size!=CS[n][m]){
        if(j==m+1){j=0;i++;}
        if(CS[i][j]>current_size){
            current_size = CS[j][j];
            track[i-1] = true;
            i++;
            continue;
        }
        j++;
    }
    for(i=0;i<n;i++)
        if(track[i]) cout<<x[i];
}
int main(){
    initialize();
    cout<<"Longest common subsequence : "<<LCS()<<" ("; print_str(); cout<<')';
}
