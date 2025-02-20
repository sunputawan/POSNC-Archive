#include <bits/stdc++.h>

using namespace std;
long long a[10],b[10],c[10],ab[10][10],bc[10][10],ca[10][10],abc[10][10][10];
long long ans;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int num; cin>>num;
        int x,y,z;
        x = num/100; num%=100;
        y = num/10; num%=10;
        z = num;
        a[x]++; b[y]++; c[z]++;
        ab[x][y]++; bc[y][z]++; ca[z][x]++;
        abc[x][y][z]++;
        ans += (a[x]+b[y]+c[z])-(ab[x][y]+bc[y][z]+ca[z][x]) + abc[x][y][z]-1;
    }
    cout<<ans<<'\n';

    return 0;
}