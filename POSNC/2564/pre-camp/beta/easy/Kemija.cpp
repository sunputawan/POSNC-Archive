#include <iostream>

using namespace std;
int main(){
    string a;
    getline(cin,a);
    for(int i=0;i<a.size();i++){
        cout<<a[i];
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            i+=2;
    }
}
