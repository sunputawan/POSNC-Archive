#include <iostream>

using namespace std;
long long pow(long long a,long long b){
    if(b==0)
        return 1;
    long long res = pow(a,b/2);
    if(b%2)
        return res*res*a;
    else
        return res*res;
}
int main(){
    long long a = 3;
    long long b = 50;
    cout<<pow(a,b);
}
