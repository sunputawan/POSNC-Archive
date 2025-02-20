#include <iostream>

using namespace std;
float select(int n,int k){
    float x=1;
    for(int i=1;i<=n-k;i++){
        x*=float(i+k)/i;
    }
    return x;
}
int main(){
    int n;
    cin>>n;
    int total=select(n,n/2);
    if(n%2==1)
        total*=2;
    cout<<total;
}
