#include <iostream>

using namespace std;

int main(){
    int A,B,C;
    cin>>A>>B>>C;
    int a,b,c,d;
    for(a=1;a<=100;a++){
        if(A%a!=0||a==0)
            continue;
        c=A/a;
        for(b=-10000;b<=10000;b++){
            if(b==0||C%b!=0)
                continue;
            d=C/b;
            if(a*d+b*c==B){
                cout<<a<<" "<<b<<" "<<c<<" "<<d;
                return 0;
            }
        }
    }
    cout<<"No Solution";
}
