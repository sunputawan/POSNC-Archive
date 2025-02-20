#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool ascending(int a,int b){
    return a<b;
}
int main(){
    vector<int> v(3);
    cin>>v[0]>>v[1]>>v[2];
    char a,b,c;
    cin>>a>>b>>c;
    std::sort(v.begin(),v.end(),ascending);
    cout<<v[a-65]<<" "<<v[b-65]<<" "<<v[c-65];
}
