#include <iostream>
#include <vector>

using namespace std;
int main(){
    int t;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++)
        cin>>a[i];
    for(int i=0;i<t;i++){
        int count=0;
        int ref=2;
        int lastest_prime = 2;
        while(count!=a[i]){
            count++;
            bool is_prime = true;
            for(int j=2;j<ref;j++){
                if(ref%j==0){ //is not prime
                    count--;
                    is_prime = false;
                    break;
                }
            }
            if(is_prime)
                lastest_prime = ref;
            ref++;
        }
        a[i]=lastest_prime;
    }
    cout<<a[0];
    /*for(int i=0;i<t;i++){
        int parent[a[i]];
        long long size[a[i]];
        for(int j=0;j<a[i];j++){
            parent[j]=j;
            size[j]=1;
        }
        for(int m=1;m<a[i]-1;m++){
            for(int n=m+1;n<a[i];n++){
                if((n*n*n-m+1)%a[i]==0||(m*m*m-n+1)&a[i]==0){

                }
            }
        }
    }*/
}
