#include <stdio.h>
int main(){
    int n,count=0;
    printf("Enter n : ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(n%i==0)
            count++;
    }
    if(count==2)
        printf("It's prime");
    else
        printf("It's not prime");
}
