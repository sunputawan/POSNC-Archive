#include <stdio.h>
#include <string.h>

char str[] = "PEATTEAP";
int boolean;
int check(char c){
    if(c == 'P')
        return 1;
    else
        return 0;
}
int main(){
    for(int i=0;i<strlen(str);i++){
        str[i] += 32;
        boolean = check(str[i]);
    }
    switch(boolean){
        case '1':
            printf("true");
            break;
        case '0':
            printf("false");
            break;
        default:
            printf("%s",str);
    }

    return 0;
}
/*
1) true
2) false
3) peatteap
4) error
*/