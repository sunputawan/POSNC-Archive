#include <bits/stdc++.h>

using namespace std;
long long qsum[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>qsum[i];
        qsum[i] += qsum[i-1];
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==r){
            cout<<0<<'\n';
            continue;
        }

        int ll = l,rr = r;
        int po = l;
        long long mn = 1e18;
        long long lsum,rsum;
        while(ll<=rr){
            int mid = (ll+rr)/2;
            long long lsum = qsum[mid-1]-qsum[l-1];
            long long rsum = qsum[r-1]-qsum[mid-1];
            if(lsum<=rsum){
                po = mid;
                ll = mid+1;
            }
            else{
                rr = mid-1;
            }
        }
        mn = min(mn,max(qsum[po-1]-qsum[l-1],qsum[r-1]-qsum[po-1]));
        mn = min(mn,max(qsum[po]-qsum[l-1],qsum[r-1]-qsum[po]));

        cout<<mn<<'\n';
    }
}
