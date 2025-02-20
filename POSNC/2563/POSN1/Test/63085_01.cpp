#include <iostream>
#include <math.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    int n=a.length();
    int x=0;
    for(int i=0;i<n;i++){
        x+=(a[i]-48)*pow(2,n-1-i);
    }
    cout<<int(x);
}
