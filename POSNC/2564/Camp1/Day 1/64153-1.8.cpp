#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main(){
    float x1,y1,x2,y2;
    cout<<"Enter pair (x1,y1) : "; cin>>x1>>y1;
    cout<<"Enter pair (x2,y2) : "; cin>>x2>>y2;
    cout<<"Distance between two points : "<<fixed<<setprecision(2)<<sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
