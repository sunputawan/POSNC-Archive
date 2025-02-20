#include <bits/stdc++.h>

using namespace std;
priority_queue<int> pq;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    char opr;
    while(n--){
        cin>>opr;
        if(opr=='P'){
            int x; cin>>x;
            pq.push(x);
        }
        else{
            if(pq.empty())
                cout<<-1<<'\n';
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
    }
    return 0;
}
