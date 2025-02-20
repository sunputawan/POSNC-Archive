#include <bits/stdc++.h>

using namespace std;
int main(){
    int n,b; cin>>n>>b;
    if(n==1){
        cout<<0<<'\n';
        return 0;
    }
    int cnt = 1;
    for(int i=3;i<=n;i+=2){
        bool is_prime = true;
        int root = sqrt(i);
        for(int j=3;j<=root;j+=2){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            cnt++;
        }
    }
    cout<<max(0,cnt-b)<<'\n';
}