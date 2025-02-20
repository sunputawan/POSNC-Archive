#include <iostream>

using namespace std;
int main(){
    int a[20],sum,min,max;
    for(int i=0;i<20;i++){
        cout<<"Enter number "<<i+1<<" : "; cin>>a[i];
    }
    sum=min=max=a[0];
    for(int i=1;i<20;i++){
        if(max<a[i]) max=a[i];
        if(min>a[i]) min=a[i];
        sum+=a[i];
    }
    cout<<"sum : "<<sum<<endl;
    cout<<"average : "<<float(sum)/20<<endl;
    cout<<"min : "<<min<<endl;
    cout<<"max : "<<max<<endl;
}
