#include <iostream>

using namespace std;
int main(){
    int n=5;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
        for(int j=0;j<a[i];j++)
            cout<<'*';
        cout<<endl;
    }
}
