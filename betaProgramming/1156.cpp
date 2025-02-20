#include <bits/stdc++.h>

using namespace std;
int k;
vector<char> v;
void play(int a,int b){
    if(a==k||b==k){
        for(auto x:v)
            cout<<x<<' ';
        cout<<'\n';
        return;
    }
    v.push_back('W');
    play(a+1,b);
    v.pop_back();

    v.push_back('L');
    play(a,b+1);
    v.pop_back();
}
int main(){
    int a,b; cin>>k>>a>>b;
    play(a,b);
}