#include <iostream>
#include <vector>

using namespace std;
int n;
int a[] = {1,2,3,5,4,6};
vector<vector<int>> d;
vector<int> front;
int roll(int i,string s){
    for(int j=0;j<s.size();j++){
        int t=d[i][0],f=d[i][1],l=d[i][2],b=d[i][3],r=d[i][4],bt=d[i][5];
        switch(s[j]){
            case 'F' : d[i][0] = b; d[i][1] = t; d[i][3] = bt; d[i][5] = f; break;
            case 'B' : d[i][0] = f; d[i][1] = bt; d[i][3] = t; d[i][5] = b; break;
            case 'L' : d[i][0] = r; d[i][2] = t; d[i][4] = bt; d[i][5] = l; break;
            case 'R' : d[i][0] = l; d[i][2] = bt; d[i][4] = t; d[i][5] = r; break;
            case 'C' : d[i][1] = r; d[i][2] = f; d[i][3] = l; d[i][4] = b; break;
            case 'D' : d[i][1] = l; d[i][2] = b; d[i][3] = r; d[i][4] = f; break;
        }
    }
    front.push_back(d[i][1]);
}
int main(){
    cin>>n;
    d.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            d[i].push_back(a[j]);
        }
    }
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        roll(i,s);
    }
    for(auto i:front)
        cout<<i<<" ";
}
