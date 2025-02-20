#include <bits/stdc++.h>

using namespace std;
int qsum[6000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    qsum[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>qsum[i];
        qsum[i]+=qsum[i-1];
    }

    deque<pair<int,int>> dq;
    int maxsum = 0;
    int minwidth = 0;
    //dq.push_back({0,0});
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&dq.back().first>=qsum[i])
            dq.pop_back();
        while(!dq.empty()&&i-dq.front().second>k)
            dq.pop_front();
        dq.push_back({qsum[i],i});
        int sum = qsum[i]-dq.front().first;
        if(sum>maxsum||(sum==maxsum&&i-dq.front().second<minwidth)){
            maxsum = sum;
            minwidth = i-dq.front().second;
        }
    }
    if(maxsum==0)
        cout<<"0\n0";
    else
        cout<<maxsum<<'\n'<<minwidth;
    return 0;
}
