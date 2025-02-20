#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

vector<int> price;
int list[]={0,1,5,8,9,10,17,17,20};
int n=10;
void generate_input(void){
    srand(time(NULL));
    price.push_back(0);
    for(int i=0;i<n;i++){
        price.push_back(rand()%20+1);
    }
    std::sort(price.begin(),price.end());
    cout<<"Price ref : ";
    for(auto i:price)
        cout<<i<<' ';
    cout<<endl;
}
//recurrence relation R(n) = max(R(n-i)+price[n-i])
int r[1000] = {};
void initialize(void){
    for(int i=0;i<=n;i++)
        r[i]=-1;
}
void print(void){
    for(int i=0;i<=n;i++)
        cout<<r[i]<<" ";
    cout<<endl;
}
int rod_cutting(int n){
    print();
    //if(n==1) return price[1];
    if(n==0) return 0;
    if(r[n]==-1){
        for(int i=1;i<=n;i++)
            r[n] = max(r[n],rod_cutting(n-i)+price[i]);
    }
    return r[n];
}
int main(){
    generate_input();
    initialize();
    cout<<endl<<rod_cutting(n);
}
