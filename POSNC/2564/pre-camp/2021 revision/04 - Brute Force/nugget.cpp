#include <iostream>

using namespace std;
bool nugget(int k,int n){
    if(k>n)
        return false;
    if(k==n)
        return true;
    return nugget(k+6,n)||nugget(k+9,n)||nugget(k+20,n);
}
int main(){
    cout<<"Enter the number :";
    for(int i=1;i<1000;i++){
        if(nugget(0,i))
            cout<<i<<" is a nugget number!";
        else
            cout<<i<<" is not a nugget number!";
        cout<<endl;
    }
}
