#include <iostream>

using namespace std;
int main(){
    int min,max;
    for(int i=0;i<10;i++){
        int a;
        cout<<"Enter a number : ";
        cin>>a;
        if(i==0)
            min=max=a;
        if(a<min) min=a;
        if(a>max) max=a;
    }
    cout<<"Min : "<<min<<endl<<"Max : "<<max;
}
