#include <iostream>

using namespace std;
int main(){
    int n;
    cin>>n;
    int i;
    int count=0;
    if(n<=0){
        return 0;
    }
    if(n==1){
        cout<<2;
        return 0;
    }
    cout<<2;
    for(i=3;count!=n-1;i++){
        int is_prime=1;
        for(int j=2;j<i;j++){
            if(i%j==0)
                is_prime=0;
        }
        if(is_prime){
            cout<<",  "<<i;
            count++;
        }
    }

}
