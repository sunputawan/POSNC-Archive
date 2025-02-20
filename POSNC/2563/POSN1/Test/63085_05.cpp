#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int count=2;
    int x=0,y=1,z=1;
    if(n<=1){
        return 0;
    }
    while(count!=n){
        int k=y;
        x=y;
        y=z;
        z=z+k;
        count++;
    }
    cout<<x<<endl<<y<<endl<<z;
}
