#include <stdio.h>
int size_s;
int subsetsum(int *s,int k,int *sp,int i){
    int sum=0;
    for(int j=0;j<size_s;j++)
        sum+=sp[j];
    if(sum==k) return 1;

    else if(i==size_s) return 0;

    else {
        if(subsetsum(s,k,sp,i+1)) return 1;
        sp[i]=s[i];
        if(subsetsum(s,k,sp,i+1)) return 1;
        sp[i]=0;
        return 0;
    }
}
int main(){
    int s[]={10,3,2,7,81,9};
    size_s=sizeof(s)/sizeof(int);
    int sp[size_s];
    int *a=s,*b=sp,k=12;
    for(int i=0;i<size_s;i++)
        b[i]=0;
    if(subsetsum(a,k,b,0)){
        printf("There is a subset of S which sum equals to %d", k);
    }
    else
        printf("There is no subset of S which sum equals to %d", k);
}

