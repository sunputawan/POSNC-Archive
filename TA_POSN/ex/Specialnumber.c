#include <stdio.h>
#include <string.h>
#include <math.h>

char str[5][10];
int i,j;
int main(){
    for(i=0;i<5;i++){
        scanf("%s",str[i]);
        int num = 0;
        int n = strlen(str[i]);
        for(j=0;j<n;j++){
            num*=10;
            num+=str[i][j]-'0';
        }
        for(j=0;j<n;j++){
            num -= pow(str[i][j]-'0',j+1);
        }
        if(num==0)
            printf("Y");
        else
            printf("N");
    }

    return 0;
}