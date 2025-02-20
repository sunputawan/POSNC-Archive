#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    float w,h;
    cout<<"Enter Weight(kg) : ";cin>>w;
    cout<<"Enter Height(m) : ";cin>>h;
    cout<<"BMI : "<<fixed<<setprecision(2)<<w/(h*h)<<" (kg/m^2)";
}
