#include <stdio.h>
int* generate_input(int n){
    int* generated_input = (int*) malloc(n*sizeof(int));
    int c, r;
    for (int i=0;i<n;i++) {
        c = rand()%10 + 1;
        r = rand() % (2*n) + 1;
        if (c > 5) generated_input[i] = r;
        else generated_input[i] = -r;
    }
    return generated_input;
}
int find_max_crossing(int *a,int low,int mid,int high){
    int left_sum=-99999;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=a[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    int right_sum=-99999;
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum=sum+a[i];
        if(sum>right_sum)
            right_sum=sum;
    }
    return(left_sum+right_sum);
}
int find_max_subarray(int *a,int low,int high){
    if(high==low)
        return a[low];
    else{
        int mid=(low+high)/2;
        int left_sum = find_max_subarray(a,low,mid);
        int right_sum = find_max_subarray(a,mid+1,high);
        int cross_sum = find_max_crossing(a,low,mid,high);
        if(left_sum>=right_sum&&left_sum>=cross_sum)
            return left_sum;
        else if(right_sum>=left_sum&&right_sum>=cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}
int main(){
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    int *s=generate_input(n);
    for(int i=0;i<n;i++)
        printf("%d,", s[i]);
    printf("\n\n%d", find_max_subarray(s,0,n-1));

}
