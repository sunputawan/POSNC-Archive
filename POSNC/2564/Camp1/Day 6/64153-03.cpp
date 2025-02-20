#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char name[20],sur[20];
    int gender;
    cout<<"name : "; cin>>name;
    cout<<"sur : "; cin>>sur;
    while(true){
        cout<<"gender (Male:1,Female:2) : "; cin>>gender;
        if(gender==1||gender==2) break;
        cout<<"Invalid input!\n";
    }
    if(gender==1) cout<<"Mr.";
    else cout<<"Mrs.";
    strcat(name," ");
    strcat(name,sur);
    cout<<name;
}
