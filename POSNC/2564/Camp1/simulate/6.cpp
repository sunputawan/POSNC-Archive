#include <iostream>

using namespace std;
int main(){
    int h,n,c;
    cout<<"h : "; cin>>h;
    cout<<"n : "; cin>>n;
    cout<<"c : "; cin>>c;
    c%=h;
    int count=0;
    char ch = 'A'-1+c;
    cout<<char(ch);
    ch++;
    count++;
    while(count!=h){
        if(ch>'O'||ch>'A'-1+h)
            ch = 'A';
        cout<<", "<<char(ch);
        count++,ch++;
    }
}
