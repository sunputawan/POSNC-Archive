/*
TASK: Gift.cpp
LANG: C++
AUTHOR: Putawan Sratongtuan
ID: 63085
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int n,k;
bool comperator(int i,int j){
    return i<=j;
}
int main(){
    cin>>k>>n;
    vector<int> v,q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push_back(a);
    }
    std::sort(q.begin(),q.end());
    int x=q.front();
    int y;
    q.erase(q.begin());
    while(!q.empty()){
        y=q.front();
        q.erase(q.begin());
        v.push_back(y-x);
        x=y;
    }
    int count=0;
    int total=0;
    std::sort(v.begin(),v.end(),comperator);
    for(auto it=v.begin();count<k;it++){
        total+=*it;
        count++;
    }
    cout<<total;
}
