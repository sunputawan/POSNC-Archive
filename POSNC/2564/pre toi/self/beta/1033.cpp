#include <bits/stdc++.h>

using namespace std;
int n,k;
int x[5];
int y[5];
int a[101][101];
int area[5];
map<char,pair<int,int>> dir;
vector<char> d[5];
void print(void){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    cin>>n>>k;
    x[1] = 1,y[1] = n,area[1] = 1;
    x[2] = n,y[2] = n,area[2] = 1;
    x[3] = n,y[3] = 1,area[3] = 1;
    x[4] = 1,y[4] = 1,area[4] = 1;
    a[1][1] = -4;
    a[1][n] = -1;
    a[n][1] = -3;
    a[n][n] = -2;
    dir['S'] = {1,0};
    dir['E'] = {0,1};
    dir['N'] = {-1,0};
    dir['W'] = {0,-1};
    int cnt = k;

    d[1].push_back(' ');
    d[2].push_back(' ');
    d[3].push_back(' ');
    d[4].push_back(' ');

    for(int i=1;i<=4;i++){
        for(int j=1;j<=k;j++){
            char c; cin>>c;
            d[i].push_back(c);
        }
    }
    int j=1;
    while(j<=k){
        for(int i=1;i<=4;i++){
            int xx = x[i]+dir[d[i][j]].first;
            int yy = y[i]+dir[d[i][j]].second;
            if(a[xx][yy]<0||xx<1||xx>n||yy<1||yy>n) continue;
            int prevArea = a[xx][yy];
            if(prevArea!=0){
                area[prevArea]--;
            }
            a[x[i]][y[i]] = i;
            a[xx][yy] = -i;
            x[i] = xx;
            y[i] = yy;
            area[i]++;
            //print();
        }
        j++;
    }
    if(area[1]+area[2]+area[3]+area[4]!=n*n){
        cout<<"No\n";
    }
    else{
        vector<int> v;
        int mx = 0;
        for(int i=1;i<=4;i++){
            mx = max(mx,area[i]);
        }
        for(int i=1;i<=4;i++){
            if(area[i]==mx)
                v.push_back(i);
        }
        cout<<v.size()<<" "<<mx<<endl;
        for(int i:v){
            cout<<i<<endl;
        }
    }
    return 0;
}
