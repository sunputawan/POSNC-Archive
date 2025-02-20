#include <bits/stdc++.h>

using namespace std;
struct domino{
    int idx,h;
};
vector<domino> v;
int mxl,mxr,idx,ansl,ansr;
int ansidx = 1;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
    }
    int cnt = 0,last_of_max = n-1;
    for(int i=n-1;i>0;i--){
        if(v[i].idx - v[i].h < v[i-1].idx){
            cnt++;
            if(cnt>=mxl){
                mxl = cnt;
                last_of_max = i+1;
            }
        }
        else{
            cnt = 0;
        }
    }
    ansl = (last_of_max+cnt-1);
    cnt = 0,last_of_max = 0;
    for(int i=0;i<n-1;i++){
        if(v[i].idx + v[i].h > v[i+1].idx){
            cnt++;
            if(cnt>mxr){
                mxr = cnt;
                last_of_max = i+1;
            }
        }
        else{
            cnt = 0;
        }
    }
    ansr = (last_of_max-cnt+1);

    if(mxl>mxr){
        cout<<ansl<<' '<<'L'<<'\n';
    }
    else if(mxr>mxl){
        cout<<ansr<<' '<<'R'<<'\n';
    }
    else if(mxl==mxr){
        if(ansl<=ansr)
            cout<<ansl<<' '<<'L'<<'\n';
        else
            cout<<ansr<<' '<<'R'<<'\n';
    }

    return 0;
}