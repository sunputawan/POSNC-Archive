#include <iostream>

using namespace std;
int prices[] = {1,3,4,5,7,9,10,11};
const int n = 8;
int R[n]={};
int main(){
    R[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            R[i] = max(R[i],prices[j-1]+R[i-j]);
        }
    }
    cout<<R[n];
}
