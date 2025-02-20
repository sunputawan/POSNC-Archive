#include <iostream>

using namespace std;
int main(){
    int sum=0;
    int a[4],b[4];
    for(int i=0;i<4;i++){
        cout<<"Enter set A's element "<<i+1<<" : ";cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<4;i++){
        cout<<"Enter set B's element "<<i+1<<" : ";cin>>b[i];
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            if(a[i]==b[j]) sum++;
    }

    if(sum==1)
        cout<<"There's "<<sum<<" duplicate! ";
    else if(sum>1)
        cout<<"There're "<<sum<<" duplicates! ";
    else
        cout<<"There's no duplicate!";
}
