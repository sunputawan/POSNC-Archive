#include  <iostream>

using namespace std;

void apply_permute(int a[],int p[],int n){
    int ans[n];
    for(int i=0;i<n;i++){
        ans[i] = a[p[i]-1];
    }
    for(int i=0;i<n;i++)
        a[i] = ans[i];

    return;
}
void pow(int p[],int k,int n){
    if(k==1)
        return;

    int ref[n];
    if(k&1){
        for(int i=0;i<n;i++)
            ref[i] = p[i];
    }
    pow(p,k/2,n);
    apply_permute(p,p,n);
    if(k&1){
        apply_permute(p,ref,n);
    }
}
void apply_permute_ktimes(int a[],int p[],int k,int n){
    if(k<1)
        return;
    pow(p,k,n);

    apply_permute(a,p,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return;
}
int main(){
    int a[] = {1,2,3,4,5,6,7};
    int p[] = {7,4,6,2,1,3,5};
    int k = 4;
    int n = 7;

    apply_permute_ktimes(a,p,k,n);

}
