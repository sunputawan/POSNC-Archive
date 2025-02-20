#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<int,long long>> peak;
vector<pair<int,long long>> ans;
int n,k;
long long h[5000000];
int min(int i,int j){
    if(i<j)
        return i;
    else
        return j;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){
    return (a.second > b.second);
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    if(h[0]>h[1]){
        pair<int,long long> x= make_pair(0,h[0]);
        peak.push_back(x);
    }
    if(h[n-1]>h[n-2]){
        pair<int,long long> x= make_pair(n-1,h[n-1]);
        peak.push_back(x);
    }
    for(int i=1;i<n-1;i++){
        if(h[i]>h[i-1]&&h[i]>h[i+1]){
            pair<int,long long> x= make_pair(i,h[i]);
            peak.push_back(x);
        }
    }
    if(peak.empty()){
        cout<<"-1";
        return 0;
    }
    int z=min(k,peak.size());
    std::sort(peak.begin(),peak.end(),sortbysec);
    ans.push_back(peak[0]);
    z--;
    for(int i=1;z>0&&i<peak.size();i++){
        if(peak[i].second!=ans[ans.size()-1].second){
            ans.push_back(peak[i]);
            z--;
        }
    }
    std::sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].second<<"\n";
    }
}
