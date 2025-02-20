#include <iostream>

using namespace std;
int main(){
    int ADyear,BEyear;
    cout<<"Enter year (A.D.) : "; cin>>ADyear;
    BEyear=ADyear+543;
    cout<<"It's "<<BEyear<<". (in B.E.)\n";
    cout<<BEyear/1000<<"+"<<(BEyear/100)%10<<"+"<<(BEyear/10)%10<<"+"<<BEyear%10<<" = "<<BEyear/1000+(BEyear/100)%10+(BEyear/10)%10+BEyear%10<<endl;
    cout<<ADyear/1000<<"+"<<(ADyear/100)%10<<"+"<<(ADyear/10)%10<<"+"<<ADyear%10<<" = "<<ADyear/1000+(ADyear/100)%10+(ADyear/10)%10+ADyear%10;
}
