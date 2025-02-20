#include <iostream>
#include <string.h>

using namespace std;
int main(){
    int n;
    char str[50];
    gets(str);
    cin>>n;
    int size_str = strlen(str);
    for(int i=0;i<n;i++){
        int k=i;
        while(k<size_str){
            if(str[k]==' ')
                cout<<'7';
            else
                cout<<str[k];
            k+=n;
        }
    }
}
