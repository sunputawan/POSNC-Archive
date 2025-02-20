#include <iostream>

using namespace std;
char a[20][20];
int b[20];
int floor[20]={};
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            a[i][j] = s[j];
        }
    }
    for(int j=0;j<n;j++){
        cin>>b[j];
        floor[j]=m;
    }
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(a[i][j]=='O')
                floor[j] = i;
        }
    }
    for(int j=0;j<n;j++){
        int i=floor[j]-1;
        while(b[j]--&&i>=0){
            a[i][j] = '#';
            i--;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<a[i][j];
        cout<<endl;
    }
}
