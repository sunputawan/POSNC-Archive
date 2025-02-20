#include <bits/stdc++.h>

using namespace std;
char m[15][85];
int r = INT_MIN, mxh = INT_MIN;
int main(){
    int n; cin>>n;
    while(n--){
        int c,h; cin>>c>>h;
        r = max(r,c+2*h-1);
        mxh = max(mxh,h);
        
        for(int i=c;i<=c+h-1;i++){
            int j = i-c+1;
            for(int k=1;k<j;k++){
                m[k][i] = 'X';
            }
            if(m[j][i]=='\\') m[j][i] = 'v';
            else if(m[j][i]!='X') m[j][i] = '/';
        }
        for(int i=c+h;i<=c+2*h-1;i++){
            int j = c+2*h-i;
            for(int k=1;k<j;k++){
                m[k][i] = 'X';
            }
            if(m[j][i]=='/') m[j][i] = 'v';
            else if(m[j][i]!='X') m[j][i] = '\\';
        }
    }

    for(int i=mxh;i>0;i--){
        for(int j=1;j<=r;j++){
            if(m[i][j]==0) cout<<'.';
            else cout<<m[i][j];
        }
        cout<<'\n';
    }
}