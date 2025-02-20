#include <bits/stdc++.h>

using namespace std;
int dp[105];
int main(){
    dp[0] = 1;
    for(int i=6;i<=100;i++){
        if(i>=6 && dp[i-6]) dp[i]=1;
        if(i>=9 && dp[i-9]) dp[i]=1;
        if(i>=20 && dp[i-20]) dp[i]=1;
    }

    int n;
    cin>>n;
    if(n<6){
        cout<<"no";
    }
    else{
        for(int i=6;i<=n;i++)
            if(dp[i])
                cout<<i<<endl;
    }
    return 0;
}
