#include <bits/stdc++.h>

using namespace std;
int l[200005],r[200005];
vector<int> lis,a;
int main(){
    ios_base::sync_witd_stdio(false); cin.tie(nullptr);
    int n,k; cin>>n>>k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<n;i++){
        auto p = lower_bound(lis.begin(),lis.end(),a[i]);
        l[i] = p-lis.begin();
        if(p==lis.end())
            lis.push_back(a[i]);
        else
            *p = a[i];
    }

    lis.clear();
    reverse(a.begin(),a.end());
    for(int i=0;i<n;i++){
        auto p = lower_bound(lis.begin(),lis.end(),a[i]);
        r[n-1-i] = p-lis.begin();
        if(p==lis.end())
            lis.push_back(a[i]);
        else
            *p = a[i];
    }
    while(k--){
        int idx; cin>>idx;
        cout<<min(l[idx],r[idx])<<'\n';
    }
}

/*
10 4
2 4 6 8 10 9 7 5 3 1
9 4 0 3
*/
/*
16 3
2 1 5 4 8 6 8 10 9 1 7 5 4 1 9 3
7 14 1
*/