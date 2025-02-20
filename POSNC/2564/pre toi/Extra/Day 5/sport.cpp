#include <bits/stdc++.h>

using namespace std;
int n;
string s;
void play(int w,int l){
    if(w==n||l==n){
        for(auto c:s)
            cout<<c<<' ';
        cout<<endl;
        return;
    }
    s.push_back('W');
    play(w+1,l);
    s.pop_back();
    s.push_back('L');
    play(w,l+1);
    s.pop_back();

    return;
}
int main(){
    int w,l;
    cin>>n>>w>>l;
    play(w,l);

    return 0;
}
