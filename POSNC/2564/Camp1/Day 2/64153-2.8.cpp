#include <iostream>

using namespace std;
int main(){
    int area;
    cout<<"Please input area : "; cin>>area;
    float rate;
    if(area>400)
        rate=5;
    else if(area>200)
        rate=7.5;
    else if(area>80)
        rate=10;
    else
        rate=12.5;

    cout<<"Total service costs : "<<area*rate<<" baht ";
}
