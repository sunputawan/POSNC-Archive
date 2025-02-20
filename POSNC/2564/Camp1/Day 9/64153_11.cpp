#include <iostream>

using namespace std;
int main(){
    string s;
    cin>>s;
    char tmp;
    int i=0;
    while(i!=s.size()){
        if(s[i]==tmp){
            i++;
            continue;
        }
        cout<<s[i];
        tmp=s[i];
        i++;
    }
}
