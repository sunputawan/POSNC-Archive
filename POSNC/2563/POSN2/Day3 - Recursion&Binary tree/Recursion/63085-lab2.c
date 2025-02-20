#include <stdio.h>
int min;
int findmin(int a[],int n){
    if(n==0)
        return min;
    else{
        if(a[n-1]<min)
            min=a[n-1];
        return findmin(a,n-1);
    }
}
int main(){
    int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int data[n];
    for(int i=0;i<n;i++){
        scanf("%d", &data[i]);
    }
    min=data[n];
    printf("%d", findmin(data,n));
}
