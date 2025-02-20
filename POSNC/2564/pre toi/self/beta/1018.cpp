#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    int x=0,y=0;
    int d = 1;   //E:1 S:2 W:3 :N:4
    while(n--){
        string str;
        cin>>str;
        int dis; cin>>dis;
        if(str[0]=='L')
            d+=3;
        else if(str[0]=='R')
            d++;
        else if(str[0]=='B')
            d+=2;
        if(d<=0) d+=4;
        else if(d>4) d-=4;
        if(d==1)
            x+=dis;
        else if(d==2)
            y-=dis;
        else if(d==3)
            x-=dis;
        else
            y+=dis;
        if(x<=-50000||x>=50000||y<=-50000||y>=50000){
            cout<<"DEAD\n";
            return 0;
        }
    }
    cout<<x<<" "<<y<<'\n';
    switch(d){
        case 1:
            cout<<"E"; break;
        case 2:
            cout<<"S"; break;
        case 3:
            cout<<"W"; break;
        case 4:
            cout<<"N"; break;
    }
    cout<<endl;
    return 0;
}
