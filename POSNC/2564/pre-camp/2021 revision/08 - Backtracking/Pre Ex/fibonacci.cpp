#include <iostream>

using namespace std;

int fibonacci(int l,int r,int n){
    if(n==1)
        return l;
    fibonacci(r,l+r,n-1);
}
int main(){
    int n = 1000;
    for(int i=1;i<=n;i++)
        cout<<fibonacci(0,1,i)<<" ";
}
