#include <iostream>

using namespace std;

int data[] = {1,2,3,4,5,6,7,8,9};
int n=sizeof(data)/sizeof(int);

int sum(int l,int r){
    cout<<"l,r : "<<l<<","<<r<<endl;
    if(l==r)
        return data[l];   //conquer
    return sum(l,(l+r)/2)+sum((l+r)/2+1,r);    //combine
}
int main(){
    cout<<endl<<"sum : "<<sum(0,n-1);
}
