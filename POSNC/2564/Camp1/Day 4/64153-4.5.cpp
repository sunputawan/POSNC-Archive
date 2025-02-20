#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter a number : "; cin>>n;
    if(n<1||n>26) {cout<<"Invalid input!"; return 0;}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<char(j+64);
        }
        cout<<endl;
    }
}
