#include <iostream>
#define pi 3.1415926

using namespace std;
int main(){
    int r;
    cout<<"Please input radius : "; cin>>r;
    cout<<"Calculator Menu :\n\t1.Find area\n\t2.Find circumference\n";
    int menu;
    cout<<"Choose menu : "; cin>>menu;
    if(menu==1){
        cout<<"Area = "<<pi*r*r;
        return 0;
    }
    else if(menu==2){
        cout<<"Circumference "<<2*pi*r;
        return 0;
    }
    else
        cout<<"Menu out of bound!";
}
