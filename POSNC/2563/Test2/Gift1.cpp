/*
TASK: Gift.cpp
LANG: C++
AUTHOR: Putawan Sratongtuan
ID: 63085
*/
#include <iostream>
#include <algorithm>
#include <vector>

int C[3000];
int n,k;
using namespace std;
int min(int x,int y){
    if(x>y)
        return x-y;
    else
        return y-x;
}
    vector<int> v;
int dynamic(int i,int j){
    if(i==0)
        return C[i];
    if(C[i]==-1){
        if(j<k)
            C[i]=min(dynamic(i-1,j),dynamic(i-2,j+1)+(v[i]-v[i-1]));
        else
            C[i]=dynamic(i-1,j);
    }
    return C[i];
}
int main(){
    cin>>k>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<n;i++){
        C[i]=-1;
    }
    std::sort(v.begin(),v.end());
    dynamic(n-1,0);
    cout<<C[n-1];
}
