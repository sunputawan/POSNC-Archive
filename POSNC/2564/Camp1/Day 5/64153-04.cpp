#include <iostream>

using namespace std;
int main(){
    int a[20],sum=0;
    for(int i=0;i<20;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
        if(a[i]%2==1)
            sum+=a[i];
    }
    cout<<"odd integer's sum : "<<sum;
}
