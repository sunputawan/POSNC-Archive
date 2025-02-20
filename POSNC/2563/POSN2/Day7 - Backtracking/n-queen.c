#include <stdio.h>
void clearq(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]='\0';
    }
}
int can_be_place(int q[],int k,int j){
    for(int i=0;i<k;i++){
        if(q[i]==j)
            return 0;
        if(q[i]==j-k+i||q[i]==j+k-i)
            return 0;
    }
    return 1;
}
void queen(int q[],int k,int n){
    if(k==n){
        for(int i=0;i<n;i++)
            printf("%d ", q[i]);
        printf("\n");
        return;
    }
    else{
        for(int j=0;j<n;j++){
            if(can_be_place(q,k,j)){
                q[k]=j;
                queen(q,k+1,n);
            }
        }
    }
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int Q[n];
    clearq(Q,n);
    queen(Q,0,n);

}
