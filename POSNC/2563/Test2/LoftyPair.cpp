/*
TASK: LoftyPair.cpp
LANG: C++
AUTHOR: Putawan Sratongtuan
ID: 63085
*/
#include <iostream>
#include <vector>
int a[1000000]={};
using namespace std;

vector<int> v,k;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    if(a[0]>a[1])
        v.push_back(0);
    for(int i=1;i<n-1;i++){
        if(a[i-1]<a[i]&&a[i]>a[i+1]){
            v.push_back(i);
        }
        if(a[i-1]>a[i]&&a[i]<a[i+1]){
            k.push_back(i);
        }
    }
    if(a[n-1]>a[n-2])
        v.push_back(n-1);
    cout<<endl;
    long long total=0;
    if(k.size()>v.size())
        k.pop_back();
    for(int i=0;i<k.size();i++){
        total+=(k[i]-v[i])*(v[i+1]-k[i]);
    }
    cout<<total;
    if(total==0){
        cout<<endl<<-1;
        return 0;
    }
    int max=0;
    for(int i=0;i<v.size()-1;i++){
        int x=a[v[i]]+a[v[i+1]];
        if(max<x)
            max=x;
    }
    cout<<endl<<max;
}
