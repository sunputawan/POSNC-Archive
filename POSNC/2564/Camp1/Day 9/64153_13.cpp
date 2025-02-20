#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]==' ')
            continue;
        cout<<"'"<<s[i]<<"' = ";
        int count=1;
        for(int j=i+1;j<s.size();j++){
            if(s[j]==s[i]){
                s[j]=' ';
                count++;
            }
        }
        cout<<count<<endl;
    }
}
