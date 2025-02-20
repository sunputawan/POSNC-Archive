#include <iostream>

using namespace std;
int a[10]={};
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=n;i<=m;i++){
        int tmp=i;
        while(tmp!=0){
            a[tmp%10]++;
            tmp/=10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<i<<" "<<a[i]<<endl;
    }
}
