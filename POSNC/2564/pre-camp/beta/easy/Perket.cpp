#include <iostream>

using namespace std;
long long int s[10],b[10];
int n;
long long int minimum=1000000000;
int diff(int a,int b){
    if(a>b)
        return a-b;
    else
        return b-a;
}
void perket(int i,long long int S,long long int B,bool empty){
    if(i==n){
        if(minimum>diff(S,B)&&!empty)
            minimum=diff(S,B);
        return;
    }
    else{
        perket(i+1,S*s[i],B+b[i],false);
        perket(i+1,S,B,empty&&true);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i]>>b[i];
    }
    perket(0,1,0,true);
    cout<<minimum;
}
