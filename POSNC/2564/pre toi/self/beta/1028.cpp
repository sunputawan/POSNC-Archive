#include <bits/stdc++.h>

using namespace std;
int val[26];
int main(){
    char c;
    while(c!='!'){
        cin>>c;
        if(c=='!')
            break;
        else if(c=='='){
            char x;int num;
            cin>>x>>num;
            val[x-'A']=num;
        }
        else if(c=='+'){
            char x,y; cin>>x>>y;
            val[x-'A']+=val[y-'A'];
        }
        else if(c=='-'){
            char x,y; cin>>x>>y;
            val[x-'A']-=val[y-'A'];
        }
        else if(c=='*'){
            char x,y; cin>>x>>y;
            val[x-'A']*=val[y-'A'];
        }
        else if(c=='/'){
            char x,y; cin>>x>>y;
            val[x-'A']/=val[y-'A'];
        }
        else if(c=='#'){
            char x; cin>>x;
            cout<<val[x-'A']<<endl;
        }
    }
    cout<<'!';
    return 0;
}
