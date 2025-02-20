#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    std::sort(a.begin(),a.end());
    if(a[0]==0){
        int i=0;
        while(a[i]==0){
            i++;
        }
        int t=a[i];
        a[i]=a[0];
        a[0]=t;
    }
    for(auto v: a){
        cout<<v;
    }
}
