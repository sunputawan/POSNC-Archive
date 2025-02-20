#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int n,m,l,k,c;
    cin>>n>>m>>l>>k>>c;
    float total=0;
    int light=0,jett=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            light+=x;
        }
    }
    jett=l*k*c;
    total=light+jett;
    total/=c;
    if(int(total)!=total)
        total++;
    cout<<int(total);
}
