#include <stdio.h>
#define size 8
int k,upbound=0;
int arraysum(int *a,int n){
    int sum=0;
    for(int i=0;i<=n;i++)
        sum+=a[i];
    return sum;
}
void knapsack(int *w,int *v,int *sw,int *sv,int i){
    if(arraysum(sw,i)>k||i==size)
        return;
    if(arraysum(sv,size-1)<upbound)
        return;
    if(arraysum(sv,i)>upbound)
        upbound=arraysum(sv,i);

    knapsack(w,v,sw,sv,i+1);
    sw[i]=0;
    sv[i]=0;
    knapsack(w,v,sw,sv,i+1);
    return;
}
int main(){
    int weight[]={3,5,5,1,7,6,6,2};
    int selected_weight[]={3,5,5,1,7,6,6,2};
    int value[]={5,4,3,4,10,6,5,7};
    int selected_value[]={5,4,3,4,10,6,5,7};
    k=15;
    int *w=weight,*v=value,*sw=selected_weight,*sv=selected_value;
    knapsack(w,v,sw,sv,0);
    printf("Max value : %d", upbound);
}
