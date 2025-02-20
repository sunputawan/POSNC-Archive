#include <iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    int i=0;
    bool cap=false,small=false;
    while(i<a.length()){
        if(a[i]<=int('Z')){
            cap=true;
        }
        if(a[i]>=('a')){
            small=true;
        }
        i++;
    }
    if(cap&&small){
        cout<<"Mix";
    }
    else if(small){
        cout<<"All Small Letter";
    }
    else
        cout<<"All Capital Letter";
}
