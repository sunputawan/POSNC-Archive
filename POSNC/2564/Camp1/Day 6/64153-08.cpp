#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char s[100];
    int h,w,bw;
    char b;
    cout<<"Enter string      ==> "; cin>>s;
    cout<<"Height string     ==> "; cin>>h;
    cout<<"Width string      ==> "; cin>>w;
    cout<<"Border Character  ==> "; cin>>b;
    cout<<"Border width      ==> "; cin>>bw;
    cout<<endl;
    for(int i=0;i<bw;i++){
        for(int j=0;j<2*bw+strlen(s)*w;j++)
            cout<<b;
        cout<<endl;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<bw;j++) cout<<b;
        for(int j=0;j<w;j++)  cout<<s;
        for(int j=0;j<bw;j++) cout<<b;
        cout<<endl;
    }
    for(int i=0;i<bw;i++){
        for(int j=0;j<2*bw+strlen(s)*w;j++)
            cout<<b;
        cout<<endl;
    }
}
