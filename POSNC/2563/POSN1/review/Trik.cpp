#include <iostream>
//#include <cstring>

using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    string a;
    cin>>a;
    int x,y,z;
    x=1,y=0,z=0;
    for(int i=0;i<a.length();i++){
        switch(a[i]){
            case 'A':{
                swap(&x,&y);
                break;
            }
            case 'B':{
                swap(&y,&z);
                break;
            }
            case 'C':{
                swap(&z,&x);
                break;
            }
        }
    }
    if(x==1){
        cout<<1;
        return 0;
    }
    if(y==1){
        cout<<2;
        return 0;
    }
    if(z==1){
        cout<<3;
        return 0;
    }
}
