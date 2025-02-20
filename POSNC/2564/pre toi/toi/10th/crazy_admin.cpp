#include <iostream>

using namespace std;
int a[100000];
int main(){
    int m,n;
    cin>>m>>n;

    for(int i=0;i<n;i++) cin>>a[i];
    int l=0, r=15e4;
    while(l<r){
        int mid = (l+r)/2, nub=1, sum=0;
        for(int i=0;i<n;i++){
            if(a[i]>mid){
                nub=m+1;
                break;
            }
            if(sum+a[i]>mid){
                sum=0;
                nub++;
            }
            sum+=a[i];
        }
        if(nub>m) l=mid+1;
        else r=mid;
    }
    cout<<l;
}
