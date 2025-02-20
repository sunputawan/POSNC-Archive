#include <iostream>

using namespace std;
int main(){
    int start,n,m=3;
    cin>>start>>n;
    int i=1;
    int count=0;
    start--;
    for(int j=0;j<start;j++)
            cout<<"   ";
    while(count!=m){
        if(i==n+1){
            count++;
            i=1;
            start+=n; start%=7;
            cout<<endl;
            for(int j=0;j<start;j++)
                cout<<"   ";
            continue;
        }
        if((i+start)%7==1) cout<<endl;
        if(i<10) cout<<' ';
        cout<<i++<<' ';
    }
}

