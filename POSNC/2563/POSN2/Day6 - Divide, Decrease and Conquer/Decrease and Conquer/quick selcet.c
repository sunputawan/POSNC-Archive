#include <stdio.h>
int n;
void print_array(int *a,int n){
    for(int i=0;i<n;i++)
        printf("%d,", a[i]);
}
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int pivot(int *a,int l,int r){
    int p=a[l];
    int s=l;
    for(int i=l+1;i<=r;i++){
        if(a[i]<p){
            s++;
            swap(&a[s],&a[i]);
        }
    }
    swap(&a[l],&a[s]);
    return s;
}
int quick_select(int *a,int l,int r,int k){
    int s=pivot(a,l,r);
            print_array(a,n);
    if(s==k-1){
        return a[s];
    }
    else if(s>k-1){
        quick_select(a,l,s-1,k);
    }
    else{
        quick_select(a,s+1,r,k);
    }
}
int main(){
    int n=12,k=7;
    int input[]={5,9,8,12,45,30,2,-7,9,5,80,0};
    int *p=input;
    printf("input[%d] : %d", k,quick_select(p,0,n-1,k));
}
