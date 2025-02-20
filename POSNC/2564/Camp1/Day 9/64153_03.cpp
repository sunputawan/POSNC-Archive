#include <iostream>

using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int a[n]={};
    char c='A'-1;
    for(int i=1;i<=n;i++){
        c+=i;
        if(c>'Z')
            c-=26;
        for(int j=n-i;j>=1;j--)
            cout<<' ';
        char tmp=c;
        for(int j=i-1;j>=0;j--){
            if(tmp=='A'-1)
                tmp='Z';
            if(j==x-1)
                a[i-1]=tmp;
            cout<<tmp;
            tmp--;
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        if(a[i]==0) continue;
        cout<<char(a[i]);
    }
}
