#include <iostream>
using namespace std;
int fibonacci(int n){
    if(n==1||n==0)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"fibinacci("<<n<<") : "<< fibonacci(n)<<endl;
}
