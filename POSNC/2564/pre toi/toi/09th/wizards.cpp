#include <iostream>

using namespace std;
struct coor{
    int x;
    int y;
}a[1501],b[1501],c[1501],d[1501];
int tx,ty,n;
const int mod = 5000011;
int hashing[mod]={};
void input(void){
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        a[i] = {x,y};
    }
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        b[i] = {x,y};
    }
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        c[i] = {x,y};
    }
    for(int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        d[i] = {x,y};
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>tx>>ty>>n;
    input();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int xx = a[i].x+b[j].x;
            int yy = a[i].y+b[j].y;

            int idx = (((2*xx+yy)%mod)+mod)%mod;
            while(hashing[idx]!=0){
                idx++;
                idx%=mod;
            }
            hashing[idx] = 1500*i+j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int xx = tx-(c[i].x+d[j].x);
            int yy = ty-(c[i].y+d[j].y);

            int idx = (((2*xx+yy)%mod)+mod)%mod;
            while(hashing[idx]!=0){
                int q = hashing[idx]/1500, r = hashing[idx]%1500;
                if(xx==a[q].x+b[r].x&&yy==a[q].y+b[r].y){
                    cout<<a[q].x<<" "<<a[q].y<<endl;
                    cout<<b[r].x<<" "<<b[r].y<<endl;
                    cout<<c[i].x<<" "<<c[i].y<<endl;
                    cout<<d[j].x<<" "<<d[j].y<<endl;
                    return 0;
                }
                idx++;
                idx%=mod;
            }
        }
    }
}
