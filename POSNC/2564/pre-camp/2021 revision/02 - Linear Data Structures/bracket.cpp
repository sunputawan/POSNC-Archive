#include <iostream>
#include <stack>

using namespace std;
stack<char> brac;
string x;
bool match(char c){
    if(brac.top()=='('&&c==')')
        return true;
    if(brac.top()=='['&&c==']')
        return true;
    if(brac.top()=='{'&&c=='}')
        return true;

    return false;
}
bool check(void){
    int i=0;
    char symb;
    while(i!=x.size()){
        symb=x[i];
        if(symb=='('||symb=='{'||symb=='['){
            brac.push(symb);
        }
        if(symb==')'||symb=='}'||symb==']'){
            if(brac.empty())
                return false;
            if(match(symb)){
                brac.pop();
            }
            else
                return false;
        }
        i++;
    }
    if(brac.empty())
        return true;
}
int main(){
    cin>>x;
    if(check())
        cout<<"Correct!";
    else
        cout<<"Incorrect!";
}
