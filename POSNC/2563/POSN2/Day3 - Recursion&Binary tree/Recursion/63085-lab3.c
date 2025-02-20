#include <stdio.h>
int sum=0;
int findsum(int a[], int n){
    if(n==0)
        return sum;
    else
        return a[n-1]+findsum(a,n-1);
}
int main(){
     int n;
    printf("Enter array size : ");
    scanf("%d", &n);
    int data[n];
    for(int i=0;i<n;i++){
        scanf("%d", &data[i]);
    }
    printf("%d", findsum(data,n));
}
