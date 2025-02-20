#include <iostream>

using namespace std;
int square(int k){
    k=abs(k);
    if(k<2)
        return k;
    if(k%2==0)
        return 4*square(k/2);
    else
        return 4*square((k-1)/2)+2*(k-1)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<square(n);
}
