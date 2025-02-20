#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main(){
    int n;
    float k;
    cin>>n;
    if(n==1){
        cout<<fixed<<setprecision(6)<<float(2);
    }
    else if(n%2==0){
        cout<<fixed<<setprecision(6)<<float(n);
    }
    else if(n==3){
        cout<<fixed<<setprecision(6)<<float(2+sqrt(3));
    }
    else{
        cout<<fixed<<setprecision(6)<<float((n-3)+2*sqrt(3));
    }

}
