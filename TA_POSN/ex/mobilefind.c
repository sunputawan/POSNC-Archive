#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[105][105];
int main(){
    int q,i,j,h,w,ii,jj,mx;
    scanf("%d",&q);
    while(q--){
        memset(a,0,sizeof(a));
        scanf("%d%d",&h,&w);
        mx = -1;
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                if(abs(a[i][j]-a[i+1][j])<=10 && a[i][j]+a[i+1][j]>mx){
                    mx = a[i][j]+a[i+1][j];
                    ii = i, jj = j;
                }
                if(abs(a[i][j]-a[i][j+1])<=10 && a[i][j]+a[i][j+1]>mx){
                    mx = a[i][j]+a[i][j+1];
                    ii = i, jj = j;
                }
            }
        }
        printf("%d %d\n",ii,jj);
    }
    return 0;
}