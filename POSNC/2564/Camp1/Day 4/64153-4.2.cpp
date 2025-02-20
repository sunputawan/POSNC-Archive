#include <iostream>

using namespace std;
int main(){
    int n,sum=0,min=100,max=0;
    cout<<"Enter n : "; cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter number : ";
        int x; cin>>x;
        if(x<0||x>100){ cout<<"Invalid input!"; return 0;}
        sum+=x;
        if(x<min) min=x;
        if(x>max) max=x;
    }
    cout<<"min : "<<min<<endl<<"max : "<<max<<endl;
    cout<<"Sum : "<<sum<<endl<<"Average : "<<float(sum)/n;
}
