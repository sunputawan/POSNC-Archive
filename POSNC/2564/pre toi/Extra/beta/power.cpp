#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
     int n; cin>>n;
     while(n--){
        ll a; cin>>a;
        bool valid = false;
        int i=2;
        i+=a%2;
        int b = sqrt(a);
        for( ;i<=b;i+=2){
            ll curval = i*i;
            int pow = 2;
            while(curval<a){
                curval*=i;
                pow++;
            }
            if(curval==a){
                cout<<pow<<endl;
                valid = true;
                break;
            }
        }
        if(!valid)
            cout<<"NO\n";
     }
}
