#include <iostream>

using namespace std;
long long pow(long long a,long long b){
    long long res =  1;
    while(b>0){
        if(b&1)     // b%2 but faster
            res*=a;
        a = a*a;
        b >>=1;
    }
    return res;
}
int main(){
    long long a = 3;
    long long b = 50;
    cout<<pow(a,b);
}
