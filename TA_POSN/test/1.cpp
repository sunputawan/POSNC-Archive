#include <stdio.h>

int main(){
    int i = 20;
    for(int i=1;i<=10;i++){
        int j=7;
        while(j++<i){
            printf("%d ",j);
        }

        if(j==i)
            printf("\n");
    }
    return 0;
}
/*
1)
2) 8
   8 9
   8 9 10

3) 8 8 9 8 9 10
4) error
*/