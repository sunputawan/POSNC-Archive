#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin>>n;
    priority_queue<int> pq;
    while(n--){
        char c;
        cin>>c;
        if(c=='P'){
            int x; cin>>x;
            pq.push(x);
        }
        else{
            if(pq.empty())
                cout<<-1<<endl;
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
    }
    return 0;
}
