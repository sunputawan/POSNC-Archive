#include <iostream>

using namespace std;
typedef long long unsigned llu;
llu m,n;
int t[1000000];
llu findsum(llu testime){
    llu sum = 0;
    for(int i=0;i<m;i++){
        sum+=(testime/t[i]);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    llu high = 1e18;
    llu low = 1;
    cin>>m>>n;
    for(int i=0;i<m;i++)
        cin>>t[i];
    for(int i=0;i<60;i++){
        llu mid = (high+low)/2;
        llu sum = findsum(mid);
        if(sum>=n)
            high=mid;
        else
            low=mid;
    }
    cout<<high;
}
