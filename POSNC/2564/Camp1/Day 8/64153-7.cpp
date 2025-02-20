#include <iostream>
#include <string.h>

using namespace std;
int a[] = {0,0,0,0,0,0,4,2,4,0};
int b[] = {0,0,0,0,0,0,9,7,9,5};
int main(){
    int c[10];
    int count=0;
    int *p,*p1,*p2;
    p=c; p1=a; p2=b;
    while(count!=10){
        *p = *p1+*p2;
        p++;p1++,p2++;
        count++;
    }
    p--;
    while(p!=c){
        if(*p>=10){
            *p-=10;
            *(p-1)+=1;
        }
        p--;
    }
    count=0;
    bool start = false;
    while(count!=10){
        if(*p!=0) start =true;
        if(start) cout<<*p;
        p++;count++;
    }
}
