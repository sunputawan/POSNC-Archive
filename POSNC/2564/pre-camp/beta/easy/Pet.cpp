#include <iostream>

using namespace std;
int main(){
    int a;
    int total[5]={};
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin>>a;
            total[i]+=a;
        }
    }
    int max=0;
    int k=0;
    for(int i=0;i<5;i++){
        if(max<total[i]){
            max=total[i];
            k=i;
        }
    }
    cout<<k+1<<" "<<total[k];
}
