#include <iostream>

using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(b<a){
        cout<<2;
        return 0;
    }
    if(b%a==0)
        cout<<b/a;
    if(b%a!=0)
        cout<<b/a+1;
}
