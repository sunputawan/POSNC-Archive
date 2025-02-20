#include <iostream>

using namespace std;
int main(){
    char c;
    cout<<"Enter a character : "; cin>>c;
    if(c>90)
        c-=32;
    while(c!=64){
        cout<<char(c)<<" ";
        c--;
    }
}
