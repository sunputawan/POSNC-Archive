#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter n : "; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Enter number "<<i+1<<" : ";cin>>a[i];
    }
    int max_count=0;
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++)
            if(a[i]==a[j]) count++;
        if(max_count<count) max_count = count;
    }
    if(max_count==1){
        cout<<"There's no mode!"; return 0;
    }
    cout<<"Mode : ";
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j<n;j++)
            if(a[i]==a[j]) count++;
        if(max_count==count) cout<<a[i]<<' ';
    }

}
