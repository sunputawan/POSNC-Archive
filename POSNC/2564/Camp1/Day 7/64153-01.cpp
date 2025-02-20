#include <iostream>

using namespace std;
int day_in_month(int m,int y){
    y-=543;
    switch(m){
        case 2:{
            if(y%4!=0) return 28;
            if(y%100!=0) return 29;
            if(y%400==0) return 29;
            return 28;
        }
        case 4:
        case 6:
        case 9:
        case 11:{
            return 30;
        }
        default:{
            return 31;
        }
    }
}
int main(){
    int m,y;
    cin>>m>>y;
    cout<<day_in_month(m,y);
}
