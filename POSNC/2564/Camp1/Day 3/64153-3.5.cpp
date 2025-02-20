#include <iostream>

using namespace std;
int main(){
    int a,b;
    cout<<"Enter two integers : "; cin>>a>>b;
    for(int i=1;i<=1000;i++){
        if(i%a==0&&i%b==0)
            cout<<i<<" ";
    }
}
