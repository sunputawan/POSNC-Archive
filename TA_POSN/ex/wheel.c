#include <stdio.h>

int a[105],b[25];
int main(){
    int n,k,i,go,now=1;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&go);
        while(go){
            if(a[now])
                go--;
            now++;
            if(now==n+1)
                now = 1;
        }
        while(a[now]==0){
            now++;
            if(now==n+1)
                now = 1;
        }
        b[(i-1)%k+1] += a[now];
        a[now] = 0;
    }
    for(i=1;i<=k;i++){
        printf("%d\n",b[i]);
    }
    return 0;
}