#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> s;
int main(){
    string a;
    int count=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]==')'){
            if(s.empty())
                count++;
            else
                s.pop();
        }
        if(a[i]=='('){
            s.push('(');
        }
    }
    count+=s.size();
    cout<<count;
}
