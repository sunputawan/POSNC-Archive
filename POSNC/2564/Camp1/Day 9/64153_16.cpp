#include <iostream>

using namespace std;
void space(int n){
    for(int i=0;i<n;i++)
        cout<<"-";
}
int main(){
    int n;
    cin>>n;
    for(int i=n;i>=2;i--){
        space(5*(n-i));
        cout<<char('A'+i-1);
        space(10*i-10+1);
        cout<<char('A'+i-1);
        space(10*(n-i)+5);
        cout<<i;
        space(10*i-10+1);
        cout<<i;
        cout<<endl<<endl;
    }
    space(5*(n-1)+1);
    cout<<'A';
    space(10*(n-1)+7);
    cout<<1<<endl<<endl;
    for(int i=2;i<=n;i++){
        space(5*(n-i));
        cout<<char('A'+i-1);
        space(10*i-10+1);
        cout<<char('A'+i-1);
        space(10*(n-i)+5);
        cout<<i;
        space(10*i-10);
        cout<<i;
        cout<<endl<<endl;
    }
}
