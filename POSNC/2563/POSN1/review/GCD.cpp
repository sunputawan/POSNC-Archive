#include <iostream>

using namespace std;
int gcd(int x,int y){
    if(x==1||y==1)
        return 1;
    else if(x>y)
        gcd(x-y,y);
    else if(x<y)
        gcd(x,y-x);
    else if(x==y)
        return x;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}
