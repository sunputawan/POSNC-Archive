#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter : "; cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++) cout<<' ';
        cout<<'\\';
        for(int j=0;j<2*(n-i-1);j++) cout<<' ';
        cout<<"/\n";
    }
}
