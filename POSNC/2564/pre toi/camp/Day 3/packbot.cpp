#include <bits/stdc++.h>

using namespace std;
int cost[] = {0,104,108,116};
int main(){
    string x; cin>>x;
    queue<int> q;
    stack<int> s;
    for(auto c:x){
        if(isalpha(c))
            q.push(20);
        else if(c=='[')
            s.push(-1);
        else if(c==']'){
            while(!s.empty()&&s.top()!=-1){
                q.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else if(c>='1'&&c<='3'){
            while(!s.empty()&&c-'0'<=s.top()){
                q.push(s.top());
                s.pop();
            }
            s.push(c-'0');
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        int a = q.front();
        q.pop();
        if(a>3){
            s.push(a);
        }
        else{
            int m = s.top(); s.pop();
            int n = s.top(); s.pop();

            s.push((m+n)*cost[a]/100);
        }
    }
    cout<<s.top();
    return 0;
}
