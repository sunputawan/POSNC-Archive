#include <bits/stdc++.h>

using namespace std;
map<int,int> mp;
int main(){
    int w,h,n;
    cin>>w>>h>>n;
    mp[0]=0;
    mp[w+1]=0;
    while(n--){
        int a,b; cin>>a>>b;
        mp[a]++;
        mp[min(w,a+b)]--;
    }

    int sum = 0;
    int last = -1;
    int cnt1 = 0;
    int cnt2 = 0;
    for(auto x:mp){
        if(last!=-1){
            if(sum>1)
                cnt2+=x.first-last;
            else if(sum==1)
                cnt1+=x.first-last;
        }

        sum += x.second;
        last = x.first;
    }
    cout<<(w-cnt1-cnt2)*h<<" "<<cnt1*h<<'\n';
}
