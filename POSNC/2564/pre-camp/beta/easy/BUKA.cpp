#include <iostream>

using namespace std;
int main(){
    string a,b;
    char x;
    cin>>a>>x>>b;
    if(x=='*'){
        cout<<'1';
        for(int i=0;i<a.length()+b.length()-2;i++)
            cout<<'0';
    }
    if(x=='+'){
        if(a.length()>b.length()){
            for(int i=0;i<a.length()-b.length();i++)
                cout<<a[i];
            cout<<b;
        }
        if(b.length()>a.length()){
            for(int i=0;i<b.length()-a.length();i++)
                cout<<b[i];
            cout<<a;
        }
        if(a.length()==b.length()){
            cout<<'2';
            for(int i=0;i<a.length()-1;i++)
                cout<<'0';
        }
    }
}
