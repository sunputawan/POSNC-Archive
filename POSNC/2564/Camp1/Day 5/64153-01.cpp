#include <iostream>

using namespace std;
int main(){
    int a[5];
    for(int i=0;i<5;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
    }
    for(int i=4;i>=0;i--)
        cout<<a[i]<<endl;
}
