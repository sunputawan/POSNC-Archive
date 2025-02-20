#include <bits/stdc++.h>

using namespace std;
int arr[300];
int main(){
    int n; cin>>n;
    int lb=300,rb=0;
    while(n--){
        int l,h,r; cin>>l>>h>>r;
        for(int i=l;i<r;i++){
            arr[i] = max(arr[i],h);
        }
        lb = min(lb,l);
        rb = max(rb,r);
    }
    int last = -1;
    for(int i=lb;i<=rb;i++){
        if(arr[i]!=last){
            cout<<i<<" "<<arr[i]<<" ";
            last = arr[i];
        }
    }
}
