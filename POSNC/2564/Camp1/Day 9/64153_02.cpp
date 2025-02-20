#include <iostream>

using namespace std;
int main(){
    int n;
    cin >>n;
    char c=65;
    int count = 0;
    int line=0;
    while(count!=n){
        if(c=='Z'+1)
            c='A';
        cout<<c;
        if((line*(line+1)-1)/2==count){
            line=0;
            cout<<endl;
        }
        c++; count++; line++;
    }
}
