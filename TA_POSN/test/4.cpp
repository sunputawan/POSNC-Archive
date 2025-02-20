#include <stdio.h>

void loop(int i,int n){
    if(i==n){
        return;
    }
    printf("%d",i+++1);
    loop(i+1,n);
}
int main(){
    loop(0,10);

    return 0;
}
/*
1) 012345678910
2) 1234567891011
3) 13579
4) 02468
*/