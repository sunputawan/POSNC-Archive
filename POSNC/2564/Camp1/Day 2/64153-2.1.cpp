#include <iostream>

using namespace std;
int main(){
    int a,b,c,d;
    cout<<"Enter score : ";
    cin>>a;
    if(a<0||a>100){
        cout<<"Invalid input!!";
        return 0;
    }
    cout<<"Enter score : ";
    cin>>b;
    if(b<0||b>100){
        cout<<"Invalid input!!";
        return 0;
    }
    cout<<"Enter score : ";
    cin>>c;
    if(c<0||c>100){
        cout<<"Invalid input!!";
        return 0;
    }
    cout<<"Enter score : ";
    cin>>d;
    if(d<0||d>100){
        cout<<"Invalid input!!";
        return 0;
    }
    cout<<"Average : "<<float(a+b+c+d)/4;
}
