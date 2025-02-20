#include <iostream>
struct node{
    int s,e;
}short_key[500];
int n,k,m;
using namespace std;
int main(){
    int a,b;
    cin>>n>>k>>m;
    for(int i=0;i<k;i++){
        cin>>a>>b;
        short_key[i].s=a;
        short_key[i].e=b;
    }

}
