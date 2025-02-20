#include <iostream>
#include <algorithm>

using namespace std;
int base(int n,int k){
    string ans;
    while(n!=0){
        if(n%k>=10) {
            ans.push_back('A'+n%k-10);
            n/=k;
            continue;
        }
        ans.push_back((n%k)+48);
        n/=k;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}
int main(){
    int n; cin>>n;
    base(n,2);
    base(n,8);
    base(n,16);
}
