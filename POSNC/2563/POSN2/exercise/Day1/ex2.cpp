#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main(){
    int a,b;
    vector<int>v={1,2,3,4,1,2,3,4};
    stack<int>s;
    for(int i=1;i<v.size();i++){
        if(v[i-1]==v[v.size()-1]){
            s.push(v[i-1]);
            v.pop_back();
        }
    }
    if(!s.empty())
        a=s.top();
    else
        a=v.front();
    b=v.back();
    cout<<a+b<<endl;
}
