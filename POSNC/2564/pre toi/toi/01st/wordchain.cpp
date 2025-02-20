#include <iostream>

using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    string s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(s[i][j]!=s[i-1][j]) count++;
            if(count>2){
                cout<<s[i-1];
                return 0;
            }
        }
    }
    cout<<s[n-1];
}
