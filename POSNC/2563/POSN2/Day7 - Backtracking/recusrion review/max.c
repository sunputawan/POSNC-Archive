#include <stdio.h>
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int max_rec(int arr[],int n){
    if(n==1)
        return arr[0];
    else{
        int a = max_rec(arr,n-1);
        int b = arr[n-1];
        return max(a,b);
    }

}
int main(){
    int a[]={7,8,5,2};
    printf("%d",max_rec(a,4));
}
