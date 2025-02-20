#include <stdio.h>
int nugget(int i){
    if(i==6||i==9||i==20)
        return 1;
    else if(i<6)
        return 0;
    else{
        return nugget(i-6)||nugget(i-9)||nugget(i-20);
    }
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        if(nugget(i))
            printf("%d ", i);
}
