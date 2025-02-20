#include <iostream>

using namespace std;
int main(){
    string x,y;
    cin>>x>>y;
    bool copy_exist=false;
    int n = x.size();
    int xindex=0;
    int yindex=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i]==y[j]){
                copy_exist = true;
                xindex=i; yindex=j;
                break;
            }
        }
    }
    if(!copy_exist){
        cout<<x;
        for(int i=0;i<n;i++){
            cout<<y[i]<<endl;
            for(int j=0;j<n;j++)
                cout<<' ';
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        if(i==yindex){
            cout<<x<<endl;
            continue;
        }
        for(int j=0;j<xindex;j++) cout<<' ';
        cout<<y[i]<<endl;
    }
}
