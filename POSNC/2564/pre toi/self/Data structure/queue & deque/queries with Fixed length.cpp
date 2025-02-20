#include <bits/stdc++.h>
#define INTMAX 1e6+5
/*

5 5
33 11 44 11 55
1
2
3
4
5

*/
using namespace std;
int n,k;
int arr[100005];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    while(k--){
        int d; cin>>d;
        deque<pair<int,int>> dq;
        int maxval = 0;
        int idx = -1;
        for(int i=1;i<=d;i++){
            if(maxval<arr[i]){
                maxval = arr[i];
                idx = i;
            }
        }
        int minimum = maxval;
        dq.push_back({maxval,idx});

        for(int i=d+1;i<=n;i++){
            while(!dq.empty()&&dq.back().first<=arr[i])
                dq.pop_back();
            while(!dq.empty()&&i-dq.front().second>=d)
                dq.pop_front();

            dq.push_back({arr[i],i});
            minimum = min(minimum,dq.front().first);
        }
        cout<<minimum<<'\n';
    }
}
