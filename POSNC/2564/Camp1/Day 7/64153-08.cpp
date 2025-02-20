#include <iostream>

using namespace std;
bool check(char c){
    if(c=='Y'||c=='y'||c=='N'||c=='n')
        return true;
    else
        return false;
}
int main(){
    char c;
    cin>>c;
    if(check(c))
        cout<<"yes";
    else
        cout<<"no";
}
