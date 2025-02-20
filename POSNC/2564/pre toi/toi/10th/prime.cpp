#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    vector<bool> mark(8000000,true);
    int n = 8000000,target;
    cin>>target;
    mark[0] = false;
    mark[1] = false;
    int sq = sqrt(n);
    int count = 0;
    for(int i=2;i<=sq;i++){
        if(!mark[i]) continue;
        count++;
        if(count==target){
            cout<<i;
            return 0;
        }
        for(int j=i*i;j<=n;j+=i){
            mark[j] = false;
        }
    }
    int i = sq;
    while(count!=target){
        i++;
        if(mark[i]) count++;
    }
    cout<<i;
}
