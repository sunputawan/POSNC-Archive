#include <stdio.h>
#include <string.h>

//N 0
//E 1
//S 2
//W 3
char str[105];
int i,dir = 0;
int main(){
    scanf("%s",str);
    int n = strlen(str);
    for(i=0;i<n;i++){
        switch(str[i]){
            case 'N':
                while(dir%4!=0){
                    dir++;
                    printf("R");
                }
                printf("F");
                break;
            case 'E':
                while(dir%4!=1){
                    dir++;
                    printf("R");
                }
                printf("F");
                break;
            case 'S':
                while(dir%4!=2){
                    dir++;
                    printf("R");
                }
                printf("F");
                break;
            case 'W':
                while(dir%4!=3){
                    dir++;
                    printf("R");
                }
                printf("F");
                break;
            case 'Z':
                printf("Z");
                dir = 0;
                break;
        }
    }

    return 0;
}