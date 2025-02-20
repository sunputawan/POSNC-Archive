/*
TASK: wheel.cpp
LANG: C++
AUTHOR: Putawan Sratongtuan
Center: SSWIT
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    int n,t,j;
    cin>>n>>t;
    string a;
    vector<string>str;
    for(int i=0;i<n;i++){
        cin>>a;
        str.push_back(a);
    }

    for(int i=1;;i++){
        int z=1;
        for(j=0;j<str.size();j++){
            if(str[j][i%str[j].length()]!=t+48){
                z=0;
                break;
            }
        }
        if(z){
            cout<<i;
            break;
        }
    }
}
