#include <bits/stdc++.h>

using namespace std;
char a[25][25];
vector<string> v;
vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int main(){
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int q; cin>>q;
    while(q--){
        string str;
        cin>>str;
        v.push_back(str);
    }
    for(int q=0;q<v.size();q++){
        bool found = false;
        int ii,jj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((a[i][j]!=v[q][0])&&(a[i][j]!=v[q][0]+32)&&(a[i][j]!=v[q][0]-32)) continue;
                int si = v[q].size();
                for(pair<int,int> d:dir){
                    int destx = (si-1)*(d.first)+i;
                    int desty = (si-1)*(d.second)+j;

                    if(destx<0||destx>=n||desty<0||desty>=m) continue;
                    int x = i,y = j;
                    found = true;
                    for(int k=1;k<si;k++){
                        x+=d.first,y+=d.second;
                        if(a[x][y]!=v[q][k]&&a[x][y]!=v[q][k]+32&&a[x][y]!=v[q][k]-32){
                            found = false;
                            break;
                        }
                    }
                    if(found){
                        ii = i;
                        jj = j;
                        break;
                    }
                }
                if(found) break;
            }
            if(found) break;
        }
        cout<<ii<<" "<<jj<<'\n';
    }
}
