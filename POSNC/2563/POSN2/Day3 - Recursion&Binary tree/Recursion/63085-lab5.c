#include <stdio.h>
#define k 5
int find(int a[],int x,int low,int hi){
    int mid=(low+hi)/2;
    if(low>hi)
        printf("Not detected!");
    else if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
        return find(a,x,low,mid-1);
    else if(a[mid]<x)
        return find(a,x,mid+1,hi);
}
void sort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j])
                swap(&a[i],&a[j]);
        }
    }
}
void swap(int *a,int *b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a,n);
    if(find(a,k,0,n-1)==-1)
        printf("Not detected!");
    else
        printf("Target : %d", find(a,k,0,n-1));
}
