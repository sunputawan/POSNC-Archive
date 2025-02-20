#include <iostream>
using namespace std;
int main(){
    int h,n,c;
    cout<<"h : ";
    cin>>h;
    cout<<"n : ";
    cin>>n;
    cout<<"c : ";
    cin>>c;
    c--;
    int j=0;
    for(int i=1;i<h;i++){
        int k=(c+j)%h;
        if(k>=14)
            c=-j-1;
        cout<<char(k+65)<<", ";
        j++;
    }
    int k=(c+j)%h;
        if(k>=14)
            c=-j-1;
        cout<<char(k+65);
}
