#include <iostream>
using namespace std;
int nugget(int n){
    if(n==0)
        return 1;
    else if(n<6)
        return 0;
    return nugget(n-6)||nugget(n-9)||nugget(n-20);

}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(nugget(i)){
            cout<<i<<endl;
        }
    }
    if(n<6)
        cout<<"no";
}
