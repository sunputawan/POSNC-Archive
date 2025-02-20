#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter a positive number : "; cin>>n;
    int i=2;
    cout<<i;
    long long unsigned ans=2;
    while(i!=n){
        i++;
        cout<<" x "<<i;
        ans*=i;
    }
    cout<<" = "<<ans;
}
