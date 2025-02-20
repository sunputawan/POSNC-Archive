#include <iostream>
#include <vector>
#define n 10000

using namespace std;
typedef long long unsigned llu;
int main(){
    //ios_base::sync_with_stdio(false);
    vector<llu> F(n);
    F[0] = 0; F[1] = 1;
    for(int i=2;i<n;i++){
        F[i] = F[i-1]+F[i-2];
    }
    for(auto i:F)
        cout<<i<<" ";
}
