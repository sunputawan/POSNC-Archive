#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float a,b,c;
    cout<<"Enter height : "; cin>>a;
    cout<<"Enter base : "; cin>>b;
    cout<<fixed<<"Your area : "<<setprecision(2)<<0.5*a*b;
}
