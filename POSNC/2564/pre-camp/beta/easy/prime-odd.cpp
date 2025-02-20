#include <iostream>

using namespace std;
string a[10];
bool check(int i){
    if(a[i]=="2")
        cout<<'T'<<endl;
    else if((a[i][a[i].size()-1]-48)%2==1)
        cout<<'T'<<endl;
    else
        cout<<'F'<<endl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        check(i);
    }
}
