#include <iostream>

using namespace std;
int cut(int n,int count){
    if(n==1)
        return count;
    else
        cut(n/2, count+1);
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<cut(a,0)+cut(b,0)+cut(c,0);
}
