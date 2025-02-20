 #include <iostream>

using namespace std;

void mid(int n){
    cout<<"*";
    for(int i=0;i<n;i++)
        cout<<"-";
    if(n>0)
    cout<<"*";
}
void edge(int n){
    for(int i=0;i<n;i++)
        cout<<"-";
}
int main(){
    int n;
    cin>>n;
    for(int i=(n-1)/2;i>=0;i--){
        edge(i);
        mid(((n-1)/2-i)*2-1);
        edge(i);
        cout<<endl;
    }
    if(n%2==0){
        mid(n-3);
        cout<<endl;
    }
    for(int i=1;i<=(n-1)/2;i++){
        edge(i);
        mid(((n-1)/2-i)*2-1);
        edge(i);
        cout<<endl;
    }
}
