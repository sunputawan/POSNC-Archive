#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter cash : "; cin>>n;
    cout<<"B1000 = "<<n/1000<<endl; n%=1000;
    cout<<"B500 = "<<n/500<<endl; n%=500;
    cout<<"B100 = "<<n/100<<endl; n%=100;
    cout<<"B50 = "<<n/50<<endl ; n%=50;
    cout<<"B20 = "<<n/20<<endl ; n%=20;
}
