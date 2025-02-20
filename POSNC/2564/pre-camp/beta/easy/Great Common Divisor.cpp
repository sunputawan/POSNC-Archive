#include <iostream>

using namespace std;
int diff(int a,int b){
    if(a>b)
        return a-b;
    else
        return b-a;
}
int gcd(int a,int b){
    if(a==b)
        return a;
    if(a>b)
        return gcd(a-b,b);
    if(a<b)
        return gcd(b-a,a);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
