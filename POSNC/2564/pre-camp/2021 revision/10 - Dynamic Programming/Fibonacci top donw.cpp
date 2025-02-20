#include <iostream>
#include <vector>
#define n 100

using namespace std;
typedef long long unsigned llu;
vector<llu> F(n,-1);
llu fibonacci(llu i){
    if(i<=0) F[i]=i;
    if(F[i]==-1)
        F[i] = fibonacci(i-1)+fibonacci(i-2);
    return F[i];
}
int main(){
    fibonacci(n-1);
    for(auto i:F)
        cout<<i<<" ";
}
