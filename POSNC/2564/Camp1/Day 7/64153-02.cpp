#include <iostream>
#include <math.h>

using namespace std;
float ans(int a,int b){
    return a+b+sqrt(a*a+b*b);
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<ans(a,b);
}
