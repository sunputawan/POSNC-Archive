#include <stdio.h>
#include <string.h>

char str[105],x,y,i;
int main(){
    scanf("%s",str);
    int n = strlen(str);
    for(i=0;i<n;i++){
        switch(str[i]){
            case 'N': y++; break;
            case 'S': y--; break;
            case 'E': x++; break;
            case 'W': x--; break;
            case 'Z': x=0,y=0; break;
        }
    }
    printf("%d %d\n",x,y);
    
    return 0;
}