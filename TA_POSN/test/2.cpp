#include <stdio.h>
int x = 123,y = 456;
void function(int x,int y){
    x = 12; y = 34;
    return;
}
int main(){
    int x,y;
    x = 1,y = 2;
    function(x,y);
    printf("%d %d",x,y);

    return 0;
}
/*
1) 123 456
2) 12 34
3) 1 2
4) error
*/