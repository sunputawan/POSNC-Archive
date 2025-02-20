#include <iostream>
#include <time.h>
#include <vector>
#define n 10000
#define INTMAX 999999
using namespace std;
vector<int> data;
int* cross(int l,int mid,int r){
    int lsum = -INTMAX;
    int sum=0;
    int leftbound;
    for(int i=mid;i>=l;i--){
        sum+=data[i];
        if(sum>lsum){
            lsum=sum;
            leftbound=i;
        }
    }
    int rsum = -INTMAX;
    sum=0;
    int rightbound;
    for(int i=mid+1;i<=r;i++){
        sum+=data[i];
        if(sum>rsum){
            rsum=sum;
            rightbound=i;
        }
    }
    int *p = new int[3];
    *p = lsum+rsum;
    *(p+1) = leftbound;
    *(p+2) = rightbound;
    return p;
}
int* maximum_subarray(int l,int r){
    if(l==r){
        int *p = new int[3];
        *p = data[l];
        *(p+1) = l;
        *(p+2) = r;
        return p;
    }
    int mid = (l+r)/2;
    int *maxleftsum = new int[3];
    int *maxrightsum = new int[3];
    int *maxcrosssum = new int[3];
    maxleftsum = maximum_subarray(l,mid);
    maxrightsum = maximum_subarray(mid+1,r);
    maxcrosssum = cross(l,mid,r);
    if(maxleftsum[0]>maxrightsum[0]&&maxleftsum[0]>maxcrosssum[0])
        return maxleftsum;
    else if(maxrightsum[0]>maxleftsum[0]&&maxrightsum[0]>maxcrosssum[0])
        return maxrightsum;
    else
        return maxcrosssum;
}
void generatelist(void){
    int x;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        x=rand()%200-100;
        data.push_back(x);
    }
}
int main(){
    generatelist();
    int *p = maximum_subarray(0,n-1);
    cout<<"Data : ";
    for(auto i : data)
        cout<<i<<" ";
    cout<<"\nMaximum subarray : ";
    cout<<p[0]<<" ["<<p[1]<<","<<p[2]<<"]\n";
}
