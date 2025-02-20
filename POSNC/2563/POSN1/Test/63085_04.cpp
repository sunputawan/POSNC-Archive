#include <iostream>

using namespace std;
int main(){
    int n;
    char a[50]={};
    gets(a);
    cin>>n;
    int l=0;
    while(a[l]!='\0')
        l++;
    for(int i=0;i<n;i++){
        for(int j=0;j<=l/n;j++){
            if(a[i+j*n]==' ')
                cout<<7;
            else if(a[i+j*n]=='\0')
                continue;
            else
                cout<<a[i+j*n];
        }
    }
}
