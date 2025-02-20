#include <stdio.h>

int arr[11], n = 5;

int main(){
    int *p = arr;
    for(int i=0;i<n;p++){
        *p = ++i;
    }
    for(int i=0;i<n;i++){
        printf("%d",*p);
        p++;
    }
    
    return 0;
}
/*
1) 00000
2) 50000
3) 12345
4) 678910
*/