#include <iostream>

using namespace std;
int n=16;
int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
int find_max_crossing(int low,int high){
    int mid=(low+high)/2;
    int left_sum=-999999;
    int right_sum=-999999;
    int sum=0;
    for(int i=mid;i>=low;i--){
        sum+=a[i];
        if(left_sum<sum)
            left_sum=sum;
    }
    sum=0;
    for(int i=mid+1;i<=high;i++){
        sum+=a[i];
        if(right_sum<sum)
            right_sum=sum;
    }
    return (left_sum+right_sum);
}
int find_max_subarray(int low,int high){
    if(high==low)
        return a[low];
    else{
        int mid=(low+high)/2;
        int left_sum=find_max_subarray(low,mid);
        int right_sum=find_max_subarray(mid+1,high);
        int cross_sum=find_max_crossing(low,high);
        if(left_sum>=right_sum&&left_sum>=cross_sum)
            return left_sum;
        else if(right_sum>=left_sum&&right_sum>=cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}
int main(){
    cout<<find_max_subarray(0,n-1);
}
