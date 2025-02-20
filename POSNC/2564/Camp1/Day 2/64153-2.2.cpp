#include <iostream>

using namespace std;
int main(){
    int odd=0,even=0;
    int a,b,c,d,e;
    cout<<"Enter 5 integers : ";
    cin>>a>>b>>c>>d>>e;
    (a%2==0) ? even++:odd++;
    (b%2==0) ? even++:odd++;
    (c%2==0) ? even++:odd++;
    (d%2==0) ? even++:odd++;
    (e%2==0) ? even++:odd++;
    cout<<"There are "<<even<<" even number(s).\n";
    cout<<"There are "<<odd<<" odd number(s).\n";
}
