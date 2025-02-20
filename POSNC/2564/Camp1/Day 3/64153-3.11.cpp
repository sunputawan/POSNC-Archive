#include <iostream>

using namespace std;
int main(){
    int start,n,m=3;
    cin>>start>>n;
    int i=1;
    for(int j=0;j<start-1;j++)
        cout<<"   ";
    while(i!=n+1){
        if((i+start)%7==2) cout<<endl;
        if(i<10) cout<<' ';
        cout<<i++<<' ';
    }
}
