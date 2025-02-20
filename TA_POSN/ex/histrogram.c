#include <stdio.h>
int arr[11111];
int main(){
    int n; scanf("%d",&n);
    int i,j;
    int maxX = -1,maxY = -1;
    for(i=0;i<n;i++){
        int a; scanf("%d",&a);
        arr[a]++;
        if(a>maxX) maxX = a;
        if(arr[a]>maxY) maxY = arr[a];
    }
    for(i=maxY;i>=1;i--){
        for(j=1;j<=maxX;j++){
            if(i<=arr[j]) printf("*");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}