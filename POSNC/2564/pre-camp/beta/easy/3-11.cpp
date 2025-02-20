#include <iostream>

using namespace std;
int main(){
    string a;
    cin>>a;
    int r3,r11=0;
    for(int i=0;i<a.length();i++){
        r3+=a[i]-48;
    }
    cout<<r3%3<<" ";
    for(int i=a.length()-1;i>=0;i--){
        if(i%2==(a.length()-1)%2)
            r11+=a[i]-48;
        else
            r11-=a[i]-48;
    }
    r11%=11;
    if(r11<0)
        r11+=11;
    cout<<r11;
}
