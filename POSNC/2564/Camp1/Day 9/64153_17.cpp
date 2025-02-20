#include <iostream>

using namespace std;
void space(int n){
    for(int i=0;i<n;i++)
        cout<<' ';
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cout<<"Input number["<<i<<"] : ";
        cin>>a[i];
    }
    cout<<' ';
    for(int i=0;i<n;i++){
        space(3);
        cout<<"_";
    }
    cout<<endl;
    for(int i=10;i>=1;i--){
        cout<<i;
        for(int j=0;j<n;j++){
            space(3);
            if(a[j]>=i) cout<<'*';
            else cout<<' ';
        }
        cout<<endl;
    }
    cout<<"0\n";
    cout<<' ';
    for(int i=0;i<n;i++){
        space(3);
        cout<<'_';
    }
    cout<<endl<<' ';
    for(int i=0;i<n;i++){
        space(3);
        cout<<i;
    }
}
