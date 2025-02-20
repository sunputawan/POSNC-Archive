#include <iostream>

using namespace std;
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.length();i++){
        if(i%3==2){
            cout<<"..*.";
        }
        else
            cout<<"..#.";
    }
    cout<<".\n";
    for(int i=0;i<a.length();i++){
        if(i%3==2){
            cout<<".*.*";
        }
        else
            cout<<".#.#";
    }
    cout<<".\n";
    cout<<"#."<<a[0]<<".";
    int i;
    for(i=1;i<a.length();i++){
        if(i%3==1){
            cout<<"#."<<a[i]<<".";
        }
        else
            cout<<"*."<<a[i]<<".";
    }
    if(i%3==0)
        cout<<"*\n";
    else
        cout<<"#\n";
    for(int i=0;i<a.length();i++){
        if(i%3==2){
            cout<<".*.*";
        }
        else
            cout<<".#.#";
    }
    cout<<".\n";
    for(int i=0;i<a.length();i++){
        if(i%3==2){
            cout<<"..*.";
        }
        else
            cout<<"..#.";
    }
    cout<<".";
}
