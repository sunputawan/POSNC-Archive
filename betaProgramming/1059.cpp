#include <bits/stdc++.h>

using namespace std;

int n,s,m;
pair<int,int> pos;
string ans;

void press(int n){
    int x = pos.first;
    int y = pos.second;
    int times = n-1;
    if(x==0){
        if(y==0)
            while(!ans.empty()&&n--)
                ans.pop_back();
        else
            ans.push_back('A'+3*(y-1)+times%3);
    }
    if(x==1){
        ans.push_back('G'+3*y+times%3);
    }
    if(x==2){
        if(y==0)
            ans.push_back('P'+times%4);
        if(y==1)
            ans.push_back('T'+times%3);
        if(y==2)
            ans.push_back('W'+times%4);
    }
    return;
}
int main(){
    cin>>n>>s>>m;
    int x,y;
    x = (s-1)/3;
    y = (s-1)%3;
    pos = make_pair(x,y);
    press(m);
    n--;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        pos.first += b;
        pos.second += a;
        press(c);
    }

    if(ans.empty()){
        cout<<"null\n";
    }
    else{
        cout<<ans<<'\n';
    }

    return 0;
}