#include <iostream>

using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int sum=a+b+c;
    switch(sum/10){
        case 10:
        case 9:
        case 8:{
            cout<<"A";
            return 0;
        }
        case 7:{
            cout<<"B";
            break;
        }
        case 6:{
            cout<<"C";
            break;
        }
        case 5:{
            cout<<"D";
            break;
        }
        case 4:
        case 3:
        case 2:
        case 1:
        case 0:{
            cout<<"F";
            return 0;
        }
    }
    if(sum%10>=5){
        cout<<"+";
    }
}

