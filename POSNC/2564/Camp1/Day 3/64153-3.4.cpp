#include <iostream>

using namespace std;
int main(){
    int n;
    int count=0;
    cout<<"Enter n : ";
    cin>>n;
    for(int i=2;i<=n;i++){
        bool is_prime = true;
        for(int j=2;j<i;j++){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            cout<<i<<" ";
            count++;
        }
    }
    cout<<"\nThere is "<<count<<" prime number(s) which less than "<<n<<"!";
}
