#include <bits/stdc++.h>

using namespace std;
long long gcd(long long a,long long b){
    if(a==0) return b;

    return gcd(b%a,a);
}
bool notprime[1000005];
int main(){
    for(long long i=2;i<=1e6;i++){
        if(!notprime[i]){
            for(long long j=i*i;j<=1e6;j+=i){
                notprime[j] = true;
            }
        }
    }

    int n; cin>>n;
    long long num=0,ans=1;
    for(int i=0;i<n;i++){
        long long a; cin>>a;
        num = gcd(num,a);
    }

    for(long long i=2;i<=1e6;i++){
        if(!notprime[i]){
            int pow = 0;
            while(num%i==0){
                pow++;
                num/=i;
            }
            ans *= (pow+1);
        }
    }
    cout<<ans<<'\n';
}