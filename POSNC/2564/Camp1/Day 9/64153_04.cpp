#include <iostream>

using namespace std;
int main(){
    int n; cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j!=1&&j!=i&&i!=n)
                sum+=j;
            cout<<j;
        }
        cout<<endl;
    }
    if(n<4) cout<<"No Answer";
    else cout<<sum;
}
