#include <bits/stdc++.h>

using namespace std;
int main(){
    int n; cin>>n;
    stack<char> s;
    while(n--){
        char c; cin>>c;
        if(!s.empty()&&s.top()!=c)
            s.push(c);
        else if(!s.empty()){
            s.pop();
        }
        else{
            s.push(c);
        }
    }
    cout<<s.size()<<'\n';
    if(s.empty()){
        cout<<"empty\n";
        return 0;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<'\n';
    return 0;
}