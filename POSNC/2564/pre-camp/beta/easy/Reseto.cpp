#include <iostream>
#include <vector>

using namespace std;
struct data{
    int number;
    bool available;
    data(){
        available=true;
    }
};
vector<data> N(1001);
int main(){
    int n,k;
    int count=0;
    cin>>n>>k;
    for(int i=2;i<=1000;i++){
        N[i].number=i;
    }
    int m=2;
    int l=2;
    int multiplier=1;
    while(count!=k){
        if(m*(multiplier)>n){
            for(int i=2;i<=1000;i++){
                if(N[i].available==true){
                    m=i;
                    l=m;
                    multiplier=1;
                    break;
                }
            }
        }
        l=m*multiplier;
        if(N[l].available==true){
            count++;
            N[l].available=false;
        }
        multiplier++;

    }
    cout<<l;
}
