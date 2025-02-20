#include <bits/stdc++.h>

using namespace std;
set<long long> s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin>>q;
    while(q--){
        s.clear();
        int n; cin>>n;
        for(int i=0;i<n;i++){
            long long x; cin>>x;
            if(s.find(x)==s.end())
                s.insert(x);
            else{
                long long a = x;
                while(s.find(a)!=s.end()){
                    s.erase(a);
                    a++;
                }
                s.insert(a);
            }
        }
        long long a = 0;
        long long ans = 0;
        for(auto i:s){
            ans+=i-a;
            a=i+1;
        }
        cout<<ans<<endl;
    }
}
