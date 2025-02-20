#include <iostream>

using namespace std;
int n,m;
int condition[8];
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void food(string s,string ans){
    if(s.length()==0){
        for(int i=0;i<m;i++){
            if(condition[i]==ans[0]-48)
                return;
        }
        for(int i=0;i<ans.length();i++)
            cout<<char(ans[i])<<" ";
        cout<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        string rest = s.substr(0,i)+s.substr(i+1);
        food(rest,ans+s[i]);
    }
}
int main(){
    cin>>n>>m;
    string ref,answer;
    for(int i=1;i<=n;i++){
        ref+=i+48;
    }
    for(int i=0;i<m;i++){
        cin>>condition[i];
    }
    food(ref,answer);
}
