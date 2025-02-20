#include <iostream>

using namespace std;
void slash(int n){
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>=0;j--)
            cout<<' ';
        cout<<'/'<<endl;
    }
}
void backslash(int n){
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            cout<<' ';
        cout<<'\\'<<endl;
    }
}
int main(){
    int menu; cin>>menu;
    int n; cin>>n;
    if(menu%2==1)
        slash(n);
    backslash(n);
    if(menu%2==0)
        slash(n);
}
