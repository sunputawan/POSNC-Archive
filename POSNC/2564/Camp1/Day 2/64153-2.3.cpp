#include <iostream>

using namespace std;
int main(){
    int id,sal,ot;
    cout<<"Enter ID : "; cin>>id;
    cout<<"Enter your salary : "; cin>>sal;
    cout<<"Enter your ot : "; cin>>ot;
    int total = sal+ot;
    cout<<'\n';
    cout<<id<<"'s total : ";
    if(total>=100000){
        cout<<total*1.1;
        return 0;
    }
    switch(total/10000){
        case 9:
        case 8:
        case 7:{
            cout<<total*1.07;
            return 0;
        }
        case 6:
        case 5:{
            cout<<total*1.05;
            return 0;
        }
        case 4:
        case 3:{
            cout<<total*1.03;
            return 0;
        }
        default :{
            cout<<total*1.01;
            return 0;
        }
    }
}
