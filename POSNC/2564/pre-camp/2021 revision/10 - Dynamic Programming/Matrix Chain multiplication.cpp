#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#define n 10

using namespace std;
//vector<int> price;
int r[1000] = {};
int price[] = {0,3,5,8,9,10,17,17,20};
/*void generate_input(void){
    srand(time(NULL));
    for(int i=0;i<=n;i++){
        price.push_back(rand()%20+1);
    }
    std::sort(price.begin(),price.end());
    price[0] = 0;
    for(auto i:price){
        if(i==*price.begin()) continue;
        cout<<i<<" ";
    }
    cout<<endl;
}*/
int cutrod(int i){
    if(i==0)
        return 0;
    if(r[i]==-1){
        for(int j=0;j<i;j++)
            r[i] = max(r[i],price[j]+cutrod(i-j-1));
    }
    return r[i];
}
int main(){
    //generate_input();
    for(int i=0;i<=n;i++){
            r[i] = -1;
    }
    cout<<cutrod(n)<<endl;
    for(int i=0;i<n;i++)
        cout<<r[i]<<" ";
}
