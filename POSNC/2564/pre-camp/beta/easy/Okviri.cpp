#include <iostream>

using namespace std;
int main(){
    string a;
    cin>>a;
    int n=a.length();
    cout<<"..#";
    for(int i=1;i<n;i++){
        cout<<"...";
        if(i%3==2)
            cout<<"*";
        else
            cout<<"#";
    }
    cout<<"..\n";
    for(int i=0;i<n;i++){
        if(i%3==2)
            cout<<".*.*";
        else
            cout<<".#.#";
    }
    cout<<".\n#";
    for(int i=0;i<n;i++){
        cout<<"."<<a[i]<<".";
        if(i%3==0||(i==n-1&&i%3==1))
            cout<<"#";
        else
            cout<<"*";
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        if(i%3==2)
            cout<<".*.*";
        else
            cout<<".#.#";
    }
    cout<<".\n..#";
    for(int i=1;i<n;i++){
        cout<<"...";
        if(i%3==2)
            cout<<"*";
        else
            cout<<"#";
    }
    cout<<"..";
}
