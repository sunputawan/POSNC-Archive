#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool ascending(int a,int b){
    return a<b;
}
int main(){
    vector<int> v;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    std::sort(v.begin(),v.end(),ascending);
    cout<<v[0]*v[2];
}
