#include <iostream>
#include <time.h>

using namespace std;
void descending(int l,int r,int *p){
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            if(p[i]<p[j]){
                int tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }
}
void ascending(int l,int r,int *p){
    for(int i=l;i<=r;i++){
        for(int j=i+1;j<=r;j++){
            if(p[i]>p[j]){
                int tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    if(n<=0) return 0;
    srand(time(NULL));
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = rand()%99+1;
    }
    descending(0,n/2,a);
    ascending(n/2+1,n-1,a);
    cout<<a[0];
    for(int i=1;i<=n/2;i++){
        cout<<" "<<a[i];
    }
    cout<<"| ";
    for(int i=n/2+1;i<n;i++){
        cout<<a[i]<<" ";
    }
}
