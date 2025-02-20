#include <iostream>

using namespace std;
int main(){
    int a[10],count=0;
    for(int i=0;i<10;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
        if(40%a[i]==0)
            count++;
    }
    cout<<"There are "<<count<<" factor(s) of 40!";
}
