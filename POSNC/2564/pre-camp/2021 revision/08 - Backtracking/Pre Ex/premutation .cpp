#include <iostream>
//#include <vector>
#include <string>

using namespace std;

void permute(string s, string p,int n){
    if(p.size()==n){
        cout<<p<<endl;
        return;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        char tmp_char = s[i];
        p.push_back(s[i]);
        s[i] = ' ';
        permute(s,p,n);
        p.pop_back();
        s[i] = tmp_char;
    }

}
int main(){
    string s = "123456", p = "";
    permute(s,p,s.size());
}
