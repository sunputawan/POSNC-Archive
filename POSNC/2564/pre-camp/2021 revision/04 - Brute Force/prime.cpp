#include <iostream>

using namespace std;
bool prime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    cout<<"Enter a number :";
    int n;
    cin>>n;
    if(prime(n))
        cout<<n<<" is a prime number!";
    else
        cout<<n<<" is not a prime number!";
}
