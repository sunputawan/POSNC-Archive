#include <iostream>

using namespace std;
int main(){
    int n,count=0;
    cin>>n;
    if(n<=0) return 0;
    else{
        count++;
        cout<<2;
    }
    for(int i=3;count!=n;i++){
        bool is_prime = true;
        for(int j=2;j<i;j++){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime){
            count++;
            cout<<", "<<i;
        }
    }
}
