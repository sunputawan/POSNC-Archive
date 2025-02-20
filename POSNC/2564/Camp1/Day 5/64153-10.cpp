#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int n=5,num=0;
    int a[n],tmp;
    cout<<"Enter 5-digit binary number : "; cin>>tmp;
    int digit=0;
    while(digit!=5){
        a[n-digit-1]=tmp%10;
        tmp/=10; digit++;
    }
    for(int i=0;i<n;i++){
        num+= a[n-i-1]*pow(2,i);
    }
    cout<<"Ans : "<<num;
}
