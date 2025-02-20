#include <iostream>

using namespace std;
int factorial(int n,int *ans){
    if(n==1) return 1;
    if(ans[n]==0)
        ans[n] = n*factorial(n-1,ans);
    return ans[n];
}
int main(){
    int n; cin>>n;
    int ans[n+1]={};
    factorial(n,ans);
    int sum=1;
    for(int i=2;i<=n;i++)
        sum+=ans[i];
    cout<<sum;
}
