#include <iostream>
#include <vector>

using namespace std;
int main(){
    vector<bool> v(42);
    for(auto i:v){
        i=false;
    }
    int count=0;
    for(int i=0;i<10;i++){
        int a;
        cin>>a;
        a%=42;
        if(v[a]==false){
            v[a]=true;
            count++;
        }
    }
    cout<<count;
}
