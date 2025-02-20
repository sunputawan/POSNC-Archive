#include <iostream>

using namespace std;
int main(){
    int m[20],n[20];
    for(int i=0;i<20;i++){
        cin>>m[i]>>n[i];
    }
    for(int i=0;i<20;i++){
        if(m[i]/2-n[i]<0||2*n[i]<m[i]/2){
            cout<<0<<endl;
            continue;
        }
        cout<<2*n[i]-m[i]/2+1<<endl;
    }
}
