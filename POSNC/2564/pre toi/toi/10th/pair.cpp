#include <iostream>

using namespace std;
int n;
char x[1005];
int dp[1005][1005]={};
int countpair(int l,int r){
    if(r-l<2||dp[l][r]!=0)
       return dp[l][r];
    else{
        if(x[l]==x[r])
            dp[l][r] = 1+countpair(l+1,r-1);
        else{
            for(int i=l;i<r;i++){
                dp[l][r] = max(dp[l][r],countpair(l,i)+countpair(i+1,r));
            }
        }
    }
    return dp[l][r];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    cout<<countpair(0,n-1)<<endl;

}
