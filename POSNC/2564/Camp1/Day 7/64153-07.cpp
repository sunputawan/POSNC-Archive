#include <iostream>

using namespace std;
int gcd(int a,int b){
    //cout<<a<<" "<<b<<endl;
    if(a==b) return a;
    if(a==1||b==1) return 1;
    if(a>b) return gcd(a-b,b);
    else return gcd(a,b-a);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    bool is_divisible = false;
    int lcm = 0;
    while(!is_divisible){
        is_divisible = true;
        lcm++;
        for(int i=0;i<n;i++)
            if(lcm%a[i]!=0){
                is_divisible=false;
                continue;
            }
    }
    cout<<"lcm = "<<lcm<<endl;
    int ans = gcd(a[0],a[1]);
    for(int i=2;i<n;i++)
        ans = gcd(ans,a[i]);
    cout<<"gcd = "<<ans;
}
