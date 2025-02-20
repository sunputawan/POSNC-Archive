#include <stdio.h>
void swap(int *x,int *y){
    int tmp=*x;
    *x=*y;
    *y=tmp;
    return;
}
int main(){
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
                swap(&a[i],&a[j]);
    }
    for(int i=0;i<n;i++)
        printf("%d ", a[i]);}
