#include <iostream>

using namespace std;
int main(){
    int n,a=1;
    cout<<"Enter n : ";cin>>n;
    for(int i=1;i<=n;i++){
        a*=2;
        cout<<i<<"\t"<<a<<endl;
    }
}
