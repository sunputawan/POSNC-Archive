#include <stdio.h>

int a[20][6];
int ans[800000][6];
int main(){
    int n,i,j,k,l,m,cnt=0; scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=5;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                for(l=1;l<=n;l++){
                    for(m=1;m<=n;m++){
                        if(a[i][1]==a[j][2]&&a[j][2]==a[k][3]&&a[k][3]==a[l][4]&&a[l][4]==a[m][5]){
                            cnt++;
                            ans[cnt][1] = i;
                            ans[cnt][2] = j;
                            ans[cnt][3] = k;
                            ans[cnt][4] = l;
                            ans[cnt][5] = m;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    for(i=1;i<=cnt;i++){
        for(j=1;j<=5;j++){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}