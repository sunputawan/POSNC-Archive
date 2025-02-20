#include <iostream>

using namespace std;
void permute(string s,string p,int n){
    if(p.size()==n){
        cout<<p<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==' ')
            continue;
        p.push_back(s[i]);
        char tmp=s[i];
        s[i]=' ';
        permute(s,p,n);
        s[i]=tmp;
        p.pop_back();
    }
}
int main(){
    string s="123456",p="";
    permute(s,p,s.size());
}
