/*
0
    0
        0

1
    0
        0
    1
        0 1

2
    0
        0
    1
        0 1
    2
        0 1 2

3
    0
        0
    1
        0 1
    2
        0 1 2
    3
        0 1 2 3

Sn = 1+2+...+n

0 = Sn;
1 = S-1
2 = Sn-2
...
n-2 = S2
n-1 = S1
*/

#include <bits/stdc++.h>
long long S[1000005];
long long sum = 0;
using namespace std;
int main(){
    for(long long i=1;i<=1000000;i++){
        S[i] = (i*(i+1))/2;
        S[i] %= 2553;
    }
    int n; cin>>n;
    for(int i=n;i>0;i--){
        long long a; cin>>a;
        sum += a*(S[i]);
        sum %= 2553;
    }

    cout<<sum<<'\n';
}
