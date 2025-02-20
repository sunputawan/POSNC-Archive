#include <stdio.h>

int gcd(int a,int b){
    if(a==0)
        return b;
    gcd(b%a,a);
}
void print_list(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    while(1){
        int n,d;
        printf("Enter n,d : ");
        scanf("%d%d",&n,&d);
        int *a = malloc(n*sizeof(int));
        printf("Enter list ref : ");
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        printf("\n");
        int g = gcd(n,d);
        for(int i=0;i<g;i++){
            int tmp = a[i];
            int k,j=i;
            while(1){
                /*printf("i,j=%d,%d : ",i,j);
                print_list(a,n);*/
                k=j+d;
                if(k>=n) k-=n;
                if(k==i) break;
                a[j] = a[k];
                j=k;
            }
            a[j] = tmp;
        }
        printf("result : ");
        print_list(a,n);
        printf("\nType \'1\' to restart program : ");
        int menu;
        scanf("%d",&menu);
        if(menu!=1)
            return 0;
    }
    return 0;
}
