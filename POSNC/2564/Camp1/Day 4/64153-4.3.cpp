#include <iostream>

using namespace std;
int main(){
    long long int n;
    cout<<"Enter n : "; cin>>n;
    if(n<0){ cout<<"Invalid input"; return 0;}

    long long int copy=n;
    int num=0;
    while(copy%10==0){
        num++;
        copy/=10;
    }
    int reverse_n=0;
    while(n!=0){
        reverse_n*=10;
        reverse_n+=n%10;
        n/=10;
    }
    cout<<"Reverse order : ";
    for(int i=0;i<num;i++) cout<<0;
    cout<<reverse_n;
}
