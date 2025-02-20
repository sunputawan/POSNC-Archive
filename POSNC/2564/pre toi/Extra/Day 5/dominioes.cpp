#include <bits/stdc++.h>

using namespace std;
int n;
string s;
void play(int i){
    if(i==n){
        for(auto c:s)
            cout<<c<<c<<endl;
        cout<<'E'<<endl;
        return;
    }
    s.push_back('-');
    play(i+1);
    s.pop_back();
    if(i<=n-2){
        s.push_back('|');
        play(i+2);
        s.pop_back();
    }
}
int main(){
    cin>>n;
    play(0);
    return 0;
}
