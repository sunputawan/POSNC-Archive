#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char a[16];
    int num=0;
    cin>>a;
    for(int i=0;i<strlen(a);i++){
        num*=2;
        if(a[i]=='1'){
            num++;
        }
    }
    cout<<num;
}
