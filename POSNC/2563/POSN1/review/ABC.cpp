#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool descending(int a,int b){
    return a<b;
}
int main(){
    int x,y,z;
    vector<int> v;
    char a,b,c;
    cin>>x>>y>>z;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    cin>>a>>b>>c;
    std::sort(v.begin(),v.end(),descending);
    cout<<v[int(a)-65]<<" "<<v[int(b)-65]<<" "<<v[int(c)-65];
}
