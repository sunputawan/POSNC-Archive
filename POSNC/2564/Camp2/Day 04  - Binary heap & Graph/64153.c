#include <stdio.h>
void insertheap(int a[],int size,int m){
    int hold=size;
    int parent=(hold-1)/2;
    while(a[parent]<m){
        a[hold]=a[parent];
        hold=parent;
        parent=(hold-1)/2;
        if(hold==0)
            break;
    }
    a[hold]=m;
    return;
}
int deleteheap(int a[],int size){
    int first=a[0];
    int last=a[size-1];
    size-=1;
    int hold=0,child;
    while(hold*2+1<size){
        int left=hold*2+1;
        int right=left+1;
        if(a[right]<a[left]){
            child=a[left];
            hold=hold*2+1;
        }
        else{
            child=a[right];
            hold=hold*2+2;
        }
        a[(hold-1)/2]=child;
        if(last>child){
            break;
        }
    }
    a[hold]=last;
    a[size]=NULL;
    return first;
}
int main(){
    int n,k;
    printf("Enter n,k:");
    scanf("%d%d", &n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        int m;
        printf("input%d : ",i+1);
        scanf("%d", &m);
        insertheap(a,i,m);
    }
    int ans;
    if(k>n)
        k=n;
    for(int i=n-1;i>=0&&k>0;i--,k--){
        ans = deleteheap(a,i+1);
    }
    printf("%d",ans);
}
