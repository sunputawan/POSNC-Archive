#include <iostream>

using namespace std;
int main(){
    int a[20],sum=0;
    for(int i=0;i<20;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
        if(a[i]>0)
            sum++;
    }
    cout<<"There are "<<sum<<" positive integer(s)";
}
