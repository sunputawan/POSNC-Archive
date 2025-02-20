#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char a[20];
    cout<<"Enter string : "; cin>>a;
    for(int i=0;i<strlen(a)&&i<20;i++){
        if(a[i]>=65&&a[i]<=90){cout<<char(a[i]+32); continue;}
        if(a[i]>=97&&a[i]<=122) {cout<<char(a[i]-32); continue;}
        cout<<char(a[i]);
    }
}
