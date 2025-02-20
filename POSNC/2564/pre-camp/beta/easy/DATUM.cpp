#include <iostream>

using namespace std;
int main(){
    int d,m;
    cin>>d>>m;
    int doy=0;
    switch(m-1){
        case 11:
            doy+=30;
        case 10:
            doy+=31;
        case 9:
            doy+=30;
        case 8:
            doy+=31;
        case 7:
            doy+=31;
        case 6:
            doy+=30;
        case 5:
            doy+=31;
        case 4:
            doy+=30;
        case 3:
            doy+=31;
        case 2:
            doy+=28;
        case 1:
            doy+=31;
    }
    doy+=d;
    switch(doy%7){
        case 0:{
            cout<<"Wednesday";
            break;
        }
        case 1:{
            cout<<"Thursday";
            break;
        }
        case 2:{
            cout<<"Friday";
            break;
        }
        case 3:{
            cout<<"Saturday";
            break;
        }
        case 4:{
            cout<<"Sunday";
            break;
        }
        case 5:{
            cout<<"Monday";
            break;
        }
        case 6:{
            cout<<"Tuesday";
            break;
        }
    }
}
