#include <iostream>

using namespace std;
int main(){
    char tmp[13],s[17];
    cout<<"Enter citizen id : "; cin>>tmp;
    int j=0;
    for(int i=0;i<13;j++){
        if(j==1||j==6||j==12||j==15){ s[j]='-'; continue;}
        s[j]=tmp[i];
        i++;
    }
    cout<<s;
}
