#include <bits/stdc++.h>

using namespace std;
string sh = "SHIFT";
string sp = "SPACEBAR";
int main(){
    int n; string s; cin>>n>>s;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='Q'||s[i]=='W'||s[i]=='E'||s[i]=='A'||s[i]=='D'||s[i]=='V'){
            cnt++;
        }
        else if(s[i]=='S'){
            cnt++;
            bool found = true;
            for(int j=1;j<5 && i+j<n;j++){
                if(s[i+j]!=sh[j]){
                    found = false;
                    break;
                }
            }
            if(found&&i+4<n){
                i+=4;
                continue;
            }
            found  = true;
            for(int j=1;j<8 && i+j<n;j++){
                if(s[i+j]!=sp[j]){
                    found = false;
                    break;
                }
            }
            if(found&&i+7<n) i+=7;
        }
    }

    cout<<cnt<<'\n';

    return 0;
}