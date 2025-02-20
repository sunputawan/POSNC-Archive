#include <iostream>

using namespace std;
int main(){
    int a[9];
    int sum=0;
    for(int i=0;i<9;i++){
        cin>>a[i];
        sum+=a[i];
    }
    int x,y;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(a[i]+a[j]+100==sum){
                x=i;
                y=j;
            }
        }
    }
    for(int i=0;i<9;i++){
        if(i==x||i==y)
            continue;
        cout<<a[i]<<endl;
    }
}
