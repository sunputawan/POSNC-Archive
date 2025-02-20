#include <bits/stdc++.h>

using namespace std;
int main(){
    int r,p,s; cin>>r>>p>>s;
    if(r+p+s!=100) cout<<"BUG\n";
    else{
        if(r>p && r>s) cout<<"PAPER\n";
        else if(p>r && p>s) cout<<"SCISSORS\n";
        else if(s>r && s>p) cout<<"ROCK\n";
        else cout<<"I DON'T KNOW\n";
    }

    return 0;
}